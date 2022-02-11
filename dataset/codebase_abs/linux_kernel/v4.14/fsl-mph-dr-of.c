static struct V_1 * F_1 ( struct V_2 * V_3 )
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
V_3 ) ;
return & V_6 [ 0 ] ;
}
static enum V_8 F_5 ( const char * V_9 )
{
if ( ! V_9 )
return V_10 ;
if ( ! strcasecmp ( V_9 , L_3 ) )
return V_11 ;
if ( ! strcasecmp ( V_9 , L_4 ) )
return V_12 ;
if ( ! strcasecmp ( V_9 , L_5 ) )
return V_13 ;
if ( ! strcasecmp ( V_9 , L_6 ) )
return V_14 ;
if ( ! strcasecmp ( V_9 , L_7 ) )
return V_15 ;
return V_10 ;
}
static struct V_16 * F_6 (
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
if ( ! V_22 -> V_29 . V_32 )
V_22 -> V_29 . V_32 = & V_17 -> V_29 . V_31 ;
else
F_8 ( & V_22 -> V_29 , F_9 ( 32 ) ) ;
V_27 = F_10 ( V_22 , V_19 , sizeof( * V_19 ) ) ;
if ( V_27 )
goto error;
if ( V_25 ) {
V_27 = F_11 ( V_22 , V_24 , V_25 ) ;
if ( V_27 )
goto error;
}
V_27 = F_12 ( V_22 ) ;
if ( V_27 )
goto error;
return V_22 ;
error:
F_13 ( V_22 ) ;
return F_14 ( V_27 ) ;
}
static enum V_33 F_15 ( struct V_2 * V_3 )
{
enum V_33 V_34 = V_35 ;
if ( F_16 ( V_3 , L_8 ) ) {
if ( F_16 ( V_3 , L_9 ) )
V_34 = V_36 ;
else if ( F_16 ( V_3 , L_10 ) )
V_34 = V_37 ;
else if ( F_16 ( V_3 , L_11 ) )
V_34 = V_38 ;
else if ( F_16 ( V_3 , L_12 ) )
V_34 = V_39 ;
else
V_34 = V_40 ;
if ( V_34 > V_35 )
return V_34 ;
}
if ( F_16 ( V_3 , L_13 ) )
return V_40 ;
if ( F_16 ( V_3 , L_14 ) ) {
if ( F_16 ( V_3 , L_15 ) )
V_34 = V_36 ;
else if ( F_16 ( V_3 , L_16 ) )
V_34 = V_37 ;
else if ( F_16 ( V_3 , L_17 ) )
V_34 = V_38 ;
else if ( F_16 ( V_3 , L_18 ) )
V_34 = V_39 ;
else
V_34 = V_40 ;
}
return V_34 ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = V_17 -> V_29 . V_41 ;
struct V_16 * V_42 ;
struct V_18 V_43 , * V_19 ;
struct V_1 * V_44 ;
const struct V_45 * V_46 ;
const unsigned char * V_4 ;
static unsigned int V_47 ;
int V_5 ;
if ( ! F_18 ( V_3 ) )
return - V_48 ;
V_46 = F_19 ( V_49 , & V_17 -> V_29 ) ;
if ( ! V_46 )
return - V_48 ;
V_19 = & V_43 ;
if ( V_46 -> V_43 )
memcpy ( V_19 , V_46 -> V_43 , sizeof( V_43 ) ) ;
else
memset ( V_19 , 0 , sizeof( V_43 ) ) ;
V_44 = F_1 ( V_3 ) ;
if ( F_16 ( V_3 , L_14 ) ) {
if ( F_2 ( V_3 , L_19 , NULL ) )
V_19 -> V_50 |= V_51 ;
if ( F_2 ( V_3 , L_20 , NULL ) )
V_19 -> V_50 |= V_52 ;
V_19 -> V_53 = V_54 ;
} else {
if ( F_2 ( V_3 , L_21 , NULL ) )
V_19 -> V_55 = 1 ;
if ( F_2 ( V_3 , L_22 , NULL ) )
V_19 -> V_56 = 1 ;
V_19 -> V_53 = V_44 -> V_57 ;
}
V_4 = F_2 ( V_3 , L_23 , NULL ) ;
V_19 -> V_58 = F_5 ( V_4 ) ;
V_19 -> V_59 = F_15 ( V_3 ) ;
V_19 -> V_60 =
F_20 ( V_3 , L_24 ) ;
V_19 -> V_61 =
F_20 ( V_3 , L_25 ) ;
V_19 -> V_62 =
F_20 ( V_3 , L_26 ) ;
V_19 -> V_63 =
F_20 ( V_3 , L_27 ) ;
if ( V_19 -> V_64 ) {
if ( V_19 -> V_59 == V_35 ) {
F_21 ( & V_17 -> V_29 , L_28 ) ;
return - V_48 ;
}
}
for ( V_5 = 0 ; V_5 < F_3 ( V_44 -> V_65 ) ; V_5 ++ ) {
if ( ! V_44 -> V_65 [ V_5 ] )
continue;
V_42 = F_6 ( V_17 , V_19 ,
V_44 -> V_65 [ V_5 ] , V_47 ) ;
if ( F_22 ( V_42 ) ) {
F_23 ( & V_17 -> V_29 , L_29 ) ;
return F_24 ( V_42 ) ;
}
}
V_47 ++ ;
return 0 ;
}
static int F_25 ( struct V_66 * V_29 , void * V_67 )
{
F_26 ( F_27 ( V_29 ) ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 )
{
F_29 ( & V_17 -> V_29 , NULL , F_25 ) ;
return 0 ;
}
int F_30 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = F_31 ( & V_22 -> V_29 ) ;
struct V_68 * V_68 ;
int V_69 ;
V_68 = F_32 ( V_22 -> V_29 . V_30 , L_30 ) ;
if ( F_22 ( V_68 ) ) {
F_23 ( & V_22 -> V_29 , L_31 ) ;
return F_24 ( V_68 ) ;
}
V_69 = F_33 ( V_68 ) ;
if ( V_69 ) {
F_23 ( & V_22 -> V_29 , L_32 ) ;
return V_69 ;
}
V_19 -> V_68 = V_68 ;
if ( V_19 -> V_58 == V_13 ) {
T_1 V_70 = 0 ;
if ( V_19 -> V_55 )
V_70 |= V_71 ;
if ( V_19 -> V_56 )
V_70 |= V_72 ;
F_34 ( V_19 -> V_73 + V_74 , V_75 | V_76 ) ;
F_34 ( V_19 -> V_73 + V_77 , V_70 ) ;
}
return 0 ;
}
static void F_35 ( struct V_16 * V_22 )
{
struct V_18 * V_19 = F_31 ( & V_22 -> V_29 ) ;
V_19 -> V_73 = NULL ;
if ( V_19 -> V_68 )
F_36 ( V_19 -> V_68 ) ;
}
