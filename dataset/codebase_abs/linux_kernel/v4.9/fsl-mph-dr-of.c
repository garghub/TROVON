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
if ( ! strcasecmp ( V_10 , L_7 ) )
return V_16 ;
return V_11 ;
}
static struct V_17 * F_6 (
struct V_17 * V_18 ,
struct V_19 * V_20 ,
const char * V_21 , int V_22 )
{
struct V_17 * V_23 ;
const struct V_24 * V_25 = V_18 -> V_24 ;
unsigned int V_26 = V_18 -> V_27 ;
int V_28 ;
V_23 = F_7 ( V_21 , V_22 ) ;
if ( ! V_23 ) {
V_28 = - V_29 ;
goto error;
}
V_23 -> V_30 . V_31 = & V_18 -> V_30 ;
V_23 -> V_30 . V_32 = V_18 -> V_30 . V_32 ;
if ( ! V_23 -> V_30 . V_33 )
V_23 -> V_30 . V_33 = & V_18 -> V_30 . V_32 ;
else
F_8 ( & V_23 -> V_30 , F_9 ( 32 ) ) ;
V_28 = F_10 ( V_23 , V_20 , sizeof( * V_20 ) ) ;
if ( V_28 )
goto error;
if ( V_26 ) {
V_28 = F_11 ( V_23 , V_25 , V_26 ) ;
if ( V_28 )
goto error;
}
V_28 = F_12 ( V_23 ) ;
if ( V_28 )
goto error;
return V_23 ;
error:
F_13 ( V_23 ) ;
return F_14 ( V_28 ) ;
}
static enum V_34 F_15 ( struct V_2 * V_3 )
{
enum V_34 V_35 = V_36 ;
if ( F_16 ( V_3 , L_8 ) ) {
if ( F_16 ( V_3 , L_9 ) )
V_35 = V_37 ;
else if ( F_16 ( V_3 , L_10 ) )
V_35 = V_38 ;
else if ( F_16 ( V_3 , L_11 ) )
V_35 = V_39 ;
else if ( F_16 ( V_3 , L_12 ) )
V_35 = V_40 ;
else
V_35 = V_41 ;
if ( V_35 > V_36 )
return V_35 ;
}
if ( F_16 ( V_3 , L_13 ) )
return V_41 ;
if ( F_16 ( V_3 , L_14 ) ) {
if ( F_16 ( V_3 , L_15 ) )
V_35 = V_37 ;
else if ( F_16 ( V_3 , L_16 ) )
V_35 = V_38 ;
else if ( F_16 ( V_3 , L_17 ) )
V_35 = V_39 ;
else if ( F_16 ( V_3 , L_18 ) )
V_35 = V_40 ;
else
V_35 = V_41 ;
}
return V_35 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = V_18 -> V_30 . V_42 ;
struct V_17 * V_43 ;
struct V_19 V_44 , * V_20 ;
struct V_1 * V_45 ;
const struct V_46 * V_47 ;
const unsigned char * V_4 ;
static unsigned int V_48 ;
int V_5 ;
if ( ! F_18 ( V_3 ) )
return - V_49 ;
V_47 = F_19 ( V_50 , & V_18 -> V_30 ) ;
if ( ! V_47 )
return - V_49 ;
V_20 = & V_44 ;
if ( V_47 -> V_44 )
memcpy ( V_20 , V_47 -> V_44 , sizeof( V_44 ) ) ;
else
memset ( V_20 , 0 , sizeof( V_44 ) ) ;
V_45 = F_1 ( V_3 ) ;
if ( F_16 ( V_3 , L_14 ) ) {
if ( F_2 ( V_3 , L_19 , NULL ) )
V_20 -> V_51 |= V_52 ;
if ( F_2 ( V_3 , L_20 , NULL ) )
V_20 -> V_51 |= V_53 ;
V_20 -> V_54 = V_55 ;
} else {
if ( F_2 ( V_3 , L_21 , NULL ) )
V_20 -> V_56 = 1 ;
if ( F_2 ( V_3 , L_22 , NULL ) )
V_20 -> V_57 = 1 ;
V_20 -> V_54 = V_45 -> V_58 ;
}
V_4 = F_2 ( V_3 , L_23 , NULL ) ;
V_20 -> V_59 = F_5 ( V_4 ) ;
V_20 -> V_60 = F_15 ( V_3 ) ;
V_20 -> V_61 =
F_20 ( V_3 , L_24 ) ;
V_20 -> V_62 =
F_20 ( V_3 , L_25 ) ;
V_20 -> V_63 =
F_20 ( V_3 , L_26 ) ;
if ( V_20 -> V_64 ) {
if ( V_20 -> V_60 == V_36 ) {
F_21 ( & V_18 -> V_30 , L_27 ) ;
return - V_49 ;
}
}
for ( V_5 = 0 ; V_5 < F_3 ( V_45 -> V_65 ) ; V_5 ++ ) {
if ( ! V_45 -> V_65 [ V_5 ] )
continue;
V_43 = F_6 ( V_18 , V_20 ,
V_45 -> V_65 [ V_5 ] , V_48 ) ;
if ( F_22 ( V_43 ) ) {
F_23 ( & V_18 -> V_30 , L_28 ) ;
return F_24 ( V_43 ) ;
}
}
V_48 ++ ;
return 0 ;
}
static int F_25 ( struct V_66 * V_30 , void * V_67 )
{
F_26 ( F_27 ( V_30 ) ) ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 )
{
F_29 ( & V_18 -> V_30 , NULL , F_25 ) ;
return 0 ;
}
int F_30 ( struct V_17 * V_23 )
{
struct V_19 * V_20 = F_31 ( & V_23 -> V_30 ) ;
struct V_68 * V_68 ;
int V_69 ;
V_68 = F_32 ( V_23 -> V_30 . V_31 , L_29 ) ;
if ( F_22 ( V_68 ) ) {
F_23 ( & V_23 -> V_30 , L_30 ) ;
return F_24 ( V_68 ) ;
}
V_69 = F_33 ( V_68 ) ;
if ( V_69 ) {
F_23 ( & V_23 -> V_30 , L_31 ) ;
return V_69 ;
}
V_20 -> V_68 = V_68 ;
if ( V_20 -> V_59 == V_14 ) {
T_1 V_70 = 0 ;
if ( V_20 -> V_56 )
V_70 |= V_71 ;
if ( V_20 -> V_57 )
V_70 |= V_72 ;
F_34 ( V_20 -> V_73 + V_74 , V_75 | V_76 ) ;
F_34 ( V_20 -> V_73 + V_77 , V_70 ) ;
}
return 0 ;
}
static void F_35 ( struct V_17 * V_23 )
{
struct V_19 * V_20 = F_31 ( & V_23 -> V_30 ) ;
V_20 -> V_73 = NULL ;
if ( V_20 -> V_68 )
F_36 ( V_20 -> V_68 ) ;
}
