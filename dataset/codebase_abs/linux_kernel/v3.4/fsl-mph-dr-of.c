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
static int T_1 F_13 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = V_17 -> V_29 . V_33 ;
struct V_16 * V_34 ;
struct V_18 V_35 , * V_19 ;
struct V_1 * V_36 ;
const struct V_37 * V_38 ;
const unsigned char * V_4 ;
static unsigned int V_39 ;
int V_5 ;
if ( ! F_14 ( V_3 ) )
return - V_40 ;
V_38 = F_15 ( V_41 , & V_17 -> V_29 ) ;
if ( ! V_38 )
return - V_40 ;
V_19 = & V_35 ;
if ( V_38 -> V_35 )
memcpy ( V_19 , V_38 -> V_35 , sizeof( V_35 ) ) ;
else
memset ( V_19 , 0 , sizeof( V_35 ) ) ;
V_36 = F_1 ( V_3 ) ;
if ( F_16 ( V_3 , L_7 ) ) {
if ( F_2 ( V_3 , L_8 , NULL ) )
V_19 -> V_42 |= V_43 ;
if ( F_2 ( V_3 , L_9 , NULL ) )
V_19 -> V_42 |= V_44 ;
V_19 -> V_45 = V_46 ;
} else {
if ( F_2 ( V_3 , L_10 , NULL ) )
V_19 -> V_47 = 1 ;
if ( F_2 ( V_3 , L_11 , NULL ) )
V_19 -> V_48 = 1 ;
V_19 -> V_45 = V_36 -> V_49 ;
}
V_4 = F_2 ( V_3 , L_12 , NULL ) ;
V_19 -> V_50 = F_5 ( V_4 ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_36 -> V_51 ) ; V_5 ++ ) {
if ( ! V_36 -> V_51 [ V_5 ] )
continue;
V_34 = F_6 ( V_17 , V_19 ,
V_36 -> V_51 [ V_5 ] , V_39 ) ;
if ( F_17 ( V_34 ) ) {
F_18 ( & V_17 -> V_29 , L_13 ) ;
return F_19 ( V_34 ) ;
}
}
V_39 ++ ;
return 0 ;
}
static int T_2 F_20 ( struct V_52 * V_29 , void * V_53 )
{
F_21 ( F_22 ( V_29 ) ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_16 * V_17 )
{
F_24 ( & V_17 -> V_29 , NULL , F_20 ) ;
return 0 ;
}
int F_25 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_54 ;
struct V_55 * V_55 ;
char V_56 [ 10 ] ;
int V_57 , V_58 ;
V_57 = V_22 -> V_23 -> V_59 & 0xf000 ;
if ( V_57 == 0x3000 )
V_58 = 1 ;
else if ( V_57 == 0x4000 )
V_58 = 2 ;
else
return - V_40 ;
snprintf ( V_56 , sizeof( V_56 ) , L_14 , V_58 ) ;
V_55 = F_26 ( & V_22 -> V_29 , V_56 ) ;
if ( F_17 ( V_55 ) ) {
F_18 ( & V_22 -> V_29 , L_15 ) ;
return F_19 ( V_55 ) ;
}
F_27 ( V_55 ) ;
V_19 -> V_55 = V_55 ;
if ( V_19 -> V_50 == V_14 ) {
T_3 V_60 = 0 ;
if ( V_19 -> V_47 )
V_60 |= V_61 ;
if ( V_19 -> V_48 )
V_60 |= V_62 ;
F_28 ( V_19 -> V_63 + V_64 , V_65 | V_66 ) ;
F_28 ( V_19 -> V_63 + V_67 , V_60 ) ;
}
return 0 ;
}
static void F_29 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_54 ;
V_19 -> V_63 = NULL ;
if ( V_19 -> V_55 ) {
F_30 ( V_19 -> V_55 ) ;
F_31 ( V_19 -> V_55 ) ;
}
}
