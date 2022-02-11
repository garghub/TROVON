struct V_1 * F_1 ( struct V_2 * V_3 )
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
static enum V_9 F_5 ( const char * V_10 )
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
struct V_16 * F_6 (
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
else if ( F_14 ( V_3 , L_10 ) )
V_33 = V_36 ;
else
V_33 = V_37 ;
if ( V_33 > - 1 )
return V_33 ;
}
if ( F_14 ( V_3 , L_11 ) )
return V_37 ;
if ( F_14 ( V_3 , L_12 ) ) {
if ( F_14 ( V_3 , L_13 ) )
V_33 = V_34 ;
else if ( F_14 ( V_3 , L_14 ) )
V_33 = V_35 ;
else
V_33 = V_37 ;
}
return V_33 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = V_17 -> V_29 . V_38 ;
struct V_16 * V_39 ;
struct V_18 V_40 , * V_19 ;
struct V_1 * V_41 ;
const struct V_42 * V_43 ;
const unsigned char * V_4 ;
static unsigned int V_44 ;
int V_5 ;
if ( ! F_16 ( V_3 ) )
return - V_45 ;
V_43 = F_17 ( V_46 , & V_17 -> V_29 ) ;
if ( ! V_43 )
return - V_45 ;
V_19 = & V_40 ;
if ( V_43 -> V_40 )
memcpy ( V_19 , V_43 -> V_40 , sizeof( V_40 ) ) ;
else
memset ( V_19 , 0 , sizeof( V_40 ) ) ;
V_41 = F_1 ( V_3 ) ;
if ( F_14 ( V_3 , L_12 ) ) {
if ( F_2 ( V_3 , L_15 , NULL ) )
V_19 -> V_47 |= V_48 ;
if ( F_2 ( V_3 , L_16 , NULL ) )
V_19 -> V_47 |= V_49 ;
V_19 -> V_50 = V_51 ;
} else {
if ( F_2 ( V_3 , L_17 , NULL ) )
V_19 -> V_52 = 1 ;
if ( F_2 ( V_3 , L_18 , NULL ) )
V_19 -> V_53 = 1 ;
V_19 -> V_50 = V_41 -> V_54 ;
}
V_4 = F_2 ( V_3 , L_19 , NULL ) ;
V_19 -> V_55 = F_5 ( V_4 ) ;
V_19 -> V_56 = F_13 ( V_3 ) ;
if ( V_19 -> V_57 ) {
if ( V_19 -> V_56 < 0 ) {
F_18 ( & V_17 -> V_29 , L_20 ) ;
return - V_45 ;
}
}
for ( V_5 = 0 ; V_5 < F_3 ( V_41 -> V_58 ) ; V_5 ++ ) {
if ( ! V_41 -> V_58 [ V_5 ] )
continue;
V_39 = F_6 ( V_17 , V_19 ,
V_41 -> V_58 [ V_5 ] , V_44 ) ;
if ( F_19 ( V_39 ) ) {
F_20 ( & V_17 -> V_29 , L_21 ) ;
return F_21 ( V_39 ) ;
}
}
V_44 ++ ;
return 0 ;
}
static int F_22 ( struct V_59 * V_29 , void * V_60 )
{
F_23 ( F_24 ( V_29 ) ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 )
{
F_26 ( & V_17 -> V_29 , NULL , F_22 ) ;
return 0 ;
}
int F_27 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_61 ;
struct V_62 * V_62 ;
char V_63 [ 10 ] ;
int V_64 , V_65 ;
V_64 = V_22 -> V_23 -> V_66 & 0xf000 ;
if ( V_64 == 0x3000 )
V_65 = 1 ;
else if ( V_64 == 0x4000 )
V_65 = 2 ;
else
return - V_45 ;
snprintf ( V_63 , sizeof( V_63 ) , L_22 , V_65 ) ;
V_62 = F_28 ( & V_22 -> V_29 , V_63 ) ;
if ( F_19 ( V_62 ) ) {
F_20 ( & V_22 -> V_29 , L_23 ) ;
return F_21 ( V_62 ) ;
}
F_29 ( V_62 ) ;
V_19 -> V_62 = V_62 ;
if ( V_19 -> V_55 == V_14 ) {
T_1 V_67 = 0 ;
if ( V_19 -> V_52 )
V_67 |= V_68 ;
if ( V_19 -> V_53 )
V_67 |= V_69 ;
F_30 ( V_19 -> V_70 + V_71 , V_72 | V_73 ) ;
F_30 ( V_19 -> V_70 + V_74 , V_67 ) ;
}
return 0 ;
}
static void F_31 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_61 ;
V_19 -> V_70 = NULL ;
if ( V_19 -> V_62 ) {
F_32 ( V_19 -> V_62 ) ;
F_33 ( V_19 -> V_62 ) ;
}
}
