void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 -> V_5 ; V_3 ++ )
F_2 ( V_2 -> V_6 [ V_3 ] . V_7 ) ;
F_2 ( V_2 ) ;
}
int F_3 ( struct V_8 * V_9 ,
struct V_1 * * V_2 )
{
struct V_10 * V_4 = F_4 () ;
int V_3 , V_11 = 0 ;
* V_2 = F_5 ( sizeof( * * V_2 ) + V_4 -> V_5 *
sizeof( struct V_12 ) , V_13 ) ;
if ( ! * V_2 )
return - V_14 ;
( * V_2 ) -> V_4 = V_4 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_15 * V_16 = V_4 -> V_17 [ V_3 ] ;
T_1 V_18 ;
V_11 = V_16 -> V_19 ( V_9 ,
& ( ( * V_2 ) -> V_6 [ V_3 ] ) ) ;
if ( V_11 != 0 )
goto V_20;
V_18 = ( * V_2 ) -> V_6 [ V_3 ] . V_18 ;
( * V_2 ) -> V_21 += sizeof( V_18 ) ;
( * V_2 ) -> V_21 += V_18 ;
}
return 0 ;
V_20:
F_1 ( * V_2 ) ;
* V_2 = NULL ;
return V_11 ;
}
int F_6 ( struct V_1 * V_2 ,
int V_22 , struct V_23 * V_23 ,
const unsigned char * V_24 , int V_25 )
{
static const char V_26 [] = L_1 ;
static const char V_27 [] = L_2 ;
char * V_28 = V_2 -> V_4 -> V_29 ;
int V_11 ;
struct {
struct V_30 V_31 ;
char V_32 [ V_33 ] ;
} V_34 ;
if ( ! V_22 ) {
int V_5 = V_2 -> V_4 -> V_5 ;
V_34 . V_31 . V_35 = V_36 ;
V_11 = F_7 ( & V_2 -> V_6 [ 0 ] ,
V_2 -> V_4 ,
V_5 , & V_34 . V_31 ) ;
if ( V_11 < 0 ) {
F_8 ( V_37 , V_23 ,
V_28 , V_26 ,
V_27 , V_11 , 0 ) ;
return V_11 ;
}
memcpy ( V_2 -> V_32 , V_34 . V_31 . V_32 , V_34 . V_31 . V_38 ) ;
}
V_2 -> V_25 = V_25 ;
V_11 = F_9 ( V_2 , V_22 , V_26 , V_23 , V_24 ) ;
return V_11 ;
}
void F_10 ( struct V_39 * V_39 , const unsigned char * V_24 ,
struct V_40 * V_41 ,
const char * V_26 , const char * V_42 )
{
struct V_1 * V_2 ;
struct V_23 * V_23 = F_11 ( V_39 ) ;
struct V_8 V_9 = { V_41 , V_39 , V_24 , NULL , 0 ,
V_42 } ;
int V_22 = 1 ;
int V_11 ;
F_12 ( & V_43 . V_44 ) ;
V_11 = F_3 ( & V_9 , & V_2 ) ;
if ( V_11 < 0 ) {
V_11 = - V_14 ;
goto V_45;
}
V_11 = F_6 ( V_2 , V_22 , V_23 ,
V_24 , V_46 ) ;
if ( V_11 < 0 )
F_1 ( V_2 ) ;
V_45:
F_8 ( V_37 , V_23 , V_24 ,
V_26 , V_42 , V_11 , 0 ) ;
}
int F_13 ( struct V_23 * V_23 , int V_47 , enum V_48 V_49 , int * V_25 )
{
int V_50 = V_51 | V_52 | V_53 ;
V_50 &= V_54 ;
return F_14 ( V_23 , V_49 , V_47 , V_50 , V_25 ) ;
}
int F_15 ( struct V_40 * V_41 ,
struct V_39 * V_39 , void * V_55 , T_2 V_56 ,
enum V_57 V_35 )
{
const char * V_27 = L_3 ;
struct V_23 * V_23 = F_11 ( V_39 ) ;
const char * V_24 = V_39 -> V_58 . V_59 -> V_60 . V_29 ;
int V_11 = 0 ;
struct {
struct V_30 V_31 ;
char V_32 [ V_61 ] ;
} V_34 ;
if ( ! ( V_41 -> V_50 & V_62 ) ) {
T_3 V_63 = F_11 ( V_39 ) -> V_63 ;
if ( V_39 -> V_64 & V_65 ) {
V_27 = L_4 ;
V_11 = - V_66 ;
goto V_20;
}
V_34 . V_31 . V_35 = V_35 ;
V_11 = ( ! V_55 ) ? F_16 ( V_39 , & V_34 . V_31 ) :
F_17 ( V_55 , V_56 , & V_34 . V_31 ) ;
if ( ! V_11 ) {
int V_38 = sizeof( V_34 . V_31 ) + V_34 . V_31 . V_38 ;
void * V_67 = F_18 ( V_41 -> V_68 , V_38 ,
V_13 ) ;
if ( V_67 ) {
V_41 -> V_68 = V_67 ;
memcpy ( V_41 -> V_68 , & V_34 , V_38 ) ;
V_41 -> V_69 = V_63 ;
V_41 -> V_50 |= V_62 ;
} else
V_11 = - V_14 ;
}
}
V_20:
if ( V_11 )
F_8 ( V_70 , V_23 ,
V_24 , L_5 , V_27 ,
V_11 , 0 ) ;
return V_11 ;
}
void F_19 ( struct V_40 * V_41 ,
struct V_39 * V_39 , const unsigned char * V_24 ,
struct V_71 * V_72 ,
int V_73 , int V_25 )
{
static const char V_26 [] = L_1 ;
static const char V_27 [] = L_6 ;
int V_11 = - V_14 ;
struct V_23 * V_23 = F_11 ( V_39 ) ;
struct V_1 * V_2 ;
struct V_8 V_9 = { V_41 , V_39 , V_24 , V_72 ,
V_73 , NULL } ;
int V_22 = 0 ;
if ( V_41 -> V_74 & ( 0x1 << V_25 ) )
return;
V_11 = F_3 ( & V_9 , & V_2 ) ;
if ( V_11 < 0 ) {
F_8 ( V_37 , V_23 , V_24 ,
V_26 , V_27 , V_11 , 0 ) ;
return;
}
V_11 = F_6 ( V_2 , V_22 , V_23 , V_24 , V_25 ) ;
if ( ! V_11 || V_11 == - V_75 ) {
V_41 -> V_50 |= V_76 ;
V_41 -> V_74 |= ( 0x1 << V_25 ) ;
}
if ( V_11 < 0 )
F_1 ( V_2 ) ;
}
void F_20 ( struct V_40 * V_41 ,
const unsigned char * V_24 )
{
struct V_77 * V_78 ;
char V_34 [ ( V_41 -> V_68 -> V_38 * 2 ) + 1 ] ;
const char * V_79 = V_80 [ V_41 -> V_68 -> V_35 ] ;
char V_81 [ sizeof( V_34 ) + strlen ( V_79 ) + 2 ] ;
int V_3 ;
if ( V_41 -> V_50 & V_82 )
return;
for ( V_3 = 0 ; V_3 < V_41 -> V_68 -> V_38 ; V_3 ++ )
F_21 ( V_34 + ( V_3 * 2 ) , V_41 -> V_68 -> V_32 [ V_3 ] ) ;
V_34 [ V_3 * 2 ] = '\0' ;
V_78 = F_22 ( V_83 -> V_84 , V_85 ,
V_86 ) ;
if ( ! V_78 )
return;
F_23 ( V_78 , L_7 ) ;
F_24 ( V_78 , V_24 ) ;
F_23 ( V_78 , L_8 ) ;
snprintf ( V_81 , sizeof( V_81 ) , L_9 , V_79 , V_34 ) ;
F_24 ( V_78 , V_81 ) ;
F_25 ( V_78 , V_83 ) ;
F_26 ( V_78 ) ;
V_41 -> V_50 |= V_82 ;
}
const char * F_27 ( const struct V_87 * V_87 , char * * V_88 , char * V_89 )
{
char * V_90 = NULL ;
* V_88 = F_28 () ;
if ( * V_88 ) {
V_90 = F_29 ( V_87 , * V_88 , V_91 ) ;
if ( F_30 ( V_90 ) ) {
F_31 ( * V_88 ) ;
* V_88 = NULL ;
V_90 = NULL ;
}
}
if ( ! V_90 ) {
F_32 ( V_89 , V_87 -> V_59 -> V_60 . V_29 , V_92 ) ;
V_90 = V_89 ;
}
return V_90 ;
}
