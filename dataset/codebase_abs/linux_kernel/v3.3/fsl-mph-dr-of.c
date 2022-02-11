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
V_22 -> V_29 . V_32 = & V_22 -> V_33 . V_32 ;
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
struct V_2 * V_3 = V_17 -> V_29 . V_34 ;
struct V_16 * V_35 ;
struct V_18 V_36 , * V_19 ;
struct V_1 * V_37 ;
const struct V_38 * V_39 ;
const unsigned char * V_4 ;
static unsigned int V_40 ;
int V_5 ;
if ( ! F_14 ( V_3 ) )
return - V_41 ;
V_39 = F_15 ( V_42 , & V_17 -> V_29 ) ;
if ( ! V_39 )
return - V_41 ;
V_19 = & V_36 ;
if ( V_39 -> V_36 )
memcpy ( V_19 , V_39 -> V_36 , sizeof( V_36 ) ) ;
else
memset ( V_19 , 0 , sizeof( V_36 ) ) ;
V_37 = F_1 ( V_3 ) ;
if ( F_16 ( V_3 , L_7 ) ) {
if ( F_2 ( V_3 , L_8 , NULL ) )
V_19 -> V_43 |= V_44 ;
if ( F_2 ( V_3 , L_9 , NULL ) )
V_19 -> V_43 |= V_45 ;
V_19 -> V_46 = V_47 ;
} else {
if ( F_2 ( V_3 , L_10 , NULL ) )
V_19 -> V_48 = 1 ;
if ( F_2 ( V_3 , L_11 , NULL ) )
V_19 -> V_49 = 1 ;
V_19 -> V_46 = V_37 -> V_50 ;
}
V_4 = F_2 ( V_3 , L_12 , NULL ) ;
V_19 -> V_51 = F_5 ( V_4 ) ;
for ( V_5 = 0 ; V_5 < F_3 ( V_37 -> V_52 ) ; V_5 ++ ) {
if ( ! V_37 -> V_52 [ V_5 ] )
continue;
V_35 = F_6 ( V_17 , V_19 ,
V_37 -> V_52 [ V_5 ] , V_40 ) ;
if ( F_17 ( V_35 ) ) {
F_18 ( & V_17 -> V_29 , L_13 ) ;
return F_19 ( V_35 ) ;
}
}
V_40 ++ ;
return 0 ;
}
static int T_2 F_20 ( struct V_53 * V_29 , void * V_54 )
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
struct V_18 * V_19 = V_22 -> V_29 . V_55 ;
struct V_56 * V_56 ;
char V_57 [ 10 ] ;
int V_58 , V_59 ;
V_58 = V_22 -> V_23 -> V_60 & 0xf000 ;
if ( V_58 == 0x3000 )
V_59 = 1 ;
else if ( V_58 == 0x4000 )
V_59 = 2 ;
else
return - V_41 ;
snprintf ( V_57 , sizeof( V_57 ) , L_14 , V_59 ) ;
V_56 = F_26 ( & V_22 -> V_29 , V_57 ) ;
if ( F_17 ( V_56 ) ) {
F_18 ( & V_22 -> V_29 , L_15 ) ;
return F_19 ( V_56 ) ;
}
F_27 ( V_56 ) ;
V_19 -> V_56 = V_56 ;
if ( V_19 -> V_51 == V_14 ) {
T_3 V_61 = 0 ;
if ( V_19 -> V_48 )
V_61 |= V_62 ;
if ( V_19 -> V_49 )
V_61 |= V_63 ;
F_28 ( V_19 -> V_64 + V_65 , V_66 | V_67 ) ;
F_28 ( V_19 -> V_64 + V_68 , V_61 ) ;
}
return 0 ;
}
static void F_29 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = V_22 -> V_29 . V_55 ;
V_19 -> V_64 = NULL ;
if ( V_19 -> V_56 ) {
F_30 ( V_19 -> V_56 ) ;
F_31 ( V_19 -> V_56 ) ;
}
}
