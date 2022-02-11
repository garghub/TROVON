struct V_1 * T_1 F_1 ( struct V_2 * V_3 )
{
const unsigned char * V_4 ;
int V_5 ;
V_4 = F_2 ( V_3 , L_1 , NULL ) ;
if ( V_4 ) {
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ ) {
if ( ! strcmp ( V_4 , V_6 [ V_5 ] . V_7 ) )
return & V_6 [ V_5 ] ;
}
}
F_4 ( L_2 ,
V_3 -> V_8 ) ;
return & V_6 [ 0 ] ;
}
static enum V_9 T_1 F_5 ( const char * V_10 )
{
if ( ! V_10 )
return V_11 ;
if ( ! strcasecmp ( V_10 , L_3 ) )
return V_12 ;
if ( ! strcasecmp ( V_10 , L_4 ) )
return V_13 ;
if ( ! strcasecmp ( V_10 , L_5 ) )
return V_14 ;
if ( ! strcasecmp ( V_10 , L_6 ) )
return V_15 ;
return V_11 ;
}
struct V_16 * T_1 F_6 (
struct V_16 * V_17 ,
struct V_18 * V_19 ,
const char * V_20 , int V_21 )
{
struct V_16 * V_22 ;
const struct V_23 * V_24 = V_17 -> V_23 ;
unsigned int V_25 = V_17 -> V_26 ;
int V_27 ;
V_22 = F_7 ( V_20 , V_21 ) ;
if ( ! V_22 ) {
V_27 = - V_28 ;
goto error;
}
V_22 -> V_29 . V_30 = & V_17 -> V_29 ;
V_22 -> V_29 . V_31 = V_17 -> V_29 . V_31 ;
* V_22 -> V_29 . V_32 = * V_17 -> V_29 . V_32 ;
V_27 = F_8 ( V_22 , V_19 , sizeof( * V_19 ) ) ;
if ( V_27 )
goto error;
if ( V_25 ) {
V_27 = F_9 ( V_22 , V_24 , V_25 ) ;
if ( V_27 )
goto error;
}
V_27 = F_10 ( V_22 ) ;
if ( V_27 )
goto error;
return V_22 ;
error:
F_11 ( V_22 ) ;
return F_12 ( V_27 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_33 = - 1 ;
if ( F_14 ( V_3 , L_7 ) ) {
if ( F_14 ( V_3 , L_8 ) )
V_33 = V_34 ;
else if ( F_14 ( V_3 , L_9 ) )
V_33 = V_35 ;
else
V_33 = V_36 ;
if ( V_33 > - 1 )
return V_33 ;
}
if ( F_14 ( V_3 , L_10 ) ) {
if ( F_14 ( V_3 , L_11 ) )
V_33 = V_34 ;
else if ( F_14 ( V_3 , L_12 ) )
V_33 = V_35 ;
else
V_33 = V_36 ;
}
return V_33 ;
}
static int T_1 F_15 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = V_17 -> V_29 . V_37 ;
struct V_16 * V_38 ;
struct V_18 V_39 , * V_19 ;
struct V_1 * V_40 ;
const struct V_41 * V_42 ;
const unsigned char * V_4 ;
static unsigned int V_43 ;
int V_5 ;
if ( ! F_16 ( V_3 ) )
return - V_44 ;
V_42 = F_17 ( V_45 , & V_17 -> V_29 ) ;
if ( ! V_42 )
return - V_44 ;
V_19 = & V_39 ;
if ( V_42 -> V_39 )
memcpy ( V_19 , V_42 -> V_39 , sizeof( V_39 ) ) ;
else
memset ( V_19 , 0 , sizeof( V_39 ) ) ;
V_40 = F_1 ( V_3 ) ;
if ( F_14 ( V_3 , L_10 ) ) {
if ( F_2 ( V_3 , L_13 , NULL ) )
V_19 -> V_46 |= V_47 ;
if ( F_2 ( V_3 , L_14 , NULL ) )
V_19 -> V_46 |= V_48 ;
V_19 -> V_49 = V_50 ;
} else {
if ( F_2 ( V_3 , L_15 , NULL ) )
V_19 -> V_51 = 1 ;
if ( F_2 ( V_3 , L_16 , NULL ) )
V_19 -> V_52 = 1 ;
V_19 -> V_49 = V_40 -> V_53 ;
}
V_4 = F_2 ( V_3 , L_17 , NULL ) ;
V_19 -> V_54 = F_5 ( V_4 ) ;
V_19 -> V_55 = F_13 ( V_3 ) ;
if ( V_19 -> V_56 ) {
if ( V_19 -> V_55 < 0 ) {
F_18 ( & V_17 -> V_29 , L_18 ) ;
return - V_44 ;
}
}
for ( V_5 = 0 ; V_5 < F_3 ( V_40 -> V_57 ) ; V_5 ++ ) {
if ( ! V_40 -> V_57 [ V_5 ] )
continue;
V_38 = F_6 ( V_17 , V_19 ,
V_40 -> V_57 [ V_5 ] , V_43 ) ;
if ( F_19 ( V_38 ) ) {
F_20 ( & V_17 -> V_29 , L_19 ) ;
return F_21 ( V_38 ) ;
}
}
V_43 ++ ;
return 0 ;
}
static int T_2 F_22 ( struct V_58 * V_29 , void * V_59 )
{
F_23 ( F_24 ( V_29 ) ) ;
return 0 ;
}
static int T_2 F_25 ( struct V_16 * V_17 )
{
F_26 ( & V_17 -> V_29 , NULL , F_22 ) ;
return 0 ;
}
int F_27 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_60 ;
struct V_61 * V_61 ;
char V_62 [ 10 ] ;
int V_63 , V_64 ;
V_63 = V_22 -> V_23 -> V_65 & 0xf000 ;
if ( V_63 == 0x3000 )
V_64 = 1 ;
else if ( V_63 == 0x4000 )
V_64 = 2 ;
else
return - V_44 ;
snprintf ( V_62 , sizeof( V_62 ) , L_20 , V_64 ) ;
V_61 = F_28 ( & V_22 -> V_29 , V_62 ) ;
if ( F_19 ( V_61 ) ) {
F_20 ( & V_22 -> V_29 , L_21 ) ;
return F_21 ( V_61 ) ;
}
F_29 ( V_61 ) ;
V_19 -> V_61 = V_61 ;
if ( V_19 -> V_54 == V_14 ) {
T_3 V_66 = 0 ;
if ( V_19 -> V_51 )
V_66 |= V_67 ;
if ( V_19 -> V_52 )
V_66 |= V_68 ;
F_30 ( V_19 -> V_69 + V_70 , V_71 | V_72 ) ;
F_30 ( V_19 -> V_69 + V_73 , V_66 ) ;
}
return 0 ;
}
static void F_31 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_60 ;
V_19 -> V_69 = NULL ;
if ( V_19 -> V_61 ) {
F_32 ( V_19 -> V_61 ) ;
F_33 ( V_19 -> V_61 ) ;
}
}
