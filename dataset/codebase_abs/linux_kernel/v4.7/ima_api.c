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
const unsigned char * V_24 )
{
static const char V_25 [] = L_1 ;
static const char V_26 [] = L_2 ;
char * V_27 = V_2 -> V_4 -> V_28 ;
int V_11 ;
struct {
struct V_29 V_30 ;
char V_31 [ V_32 ] ;
} V_33 ;
if ( ! V_22 ) {
int V_5 = V_2 -> V_4 -> V_5 ;
V_33 . V_30 . V_34 = V_35 ;
V_11 = F_7 ( & V_2 -> V_6 [ 0 ] ,
V_2 -> V_4 ,
V_5 , & V_33 . V_30 ) ;
if ( V_11 < 0 ) {
F_8 ( V_36 , V_23 ,
V_27 , V_25 ,
V_26 , V_11 , 0 ) ;
return V_11 ;
}
memcpy ( V_2 -> V_31 , V_33 . V_30 . V_31 , V_33 . V_30 . V_37 ) ;
}
V_11 = F_9 ( V_2 , V_22 , V_25 , V_23 , V_24 ) ;
return V_11 ;
}
void F_10 ( struct V_38 * V_38 , const unsigned char * V_24 ,
struct V_39 * V_40 ,
const char * V_25 , const char * V_41 )
{
struct V_1 * V_2 ;
struct V_23 * V_23 = F_11 ( V_38 ) ;
struct V_8 V_9 = { V_40 , V_38 , V_24 , NULL , 0 ,
V_41 } ;
int V_22 = 1 ;
int V_11 ;
F_12 ( & V_42 . V_43 ) ;
V_11 = F_3 ( & V_9 , & V_2 ) ;
if ( V_11 < 0 ) {
V_11 = - V_14 ;
goto V_44;
}
V_11 = F_6 ( V_2 , V_22 , V_23 , V_24 ) ;
if ( V_11 < 0 )
F_1 ( V_2 ) ;
V_44:
F_8 ( V_36 , V_23 , V_24 ,
V_25 , V_41 , V_11 , 0 ) ;
}
int F_13 ( struct V_23 * V_23 , int V_45 , enum V_46 V_47 )
{
int V_48 = V_49 | V_50 | V_51 ;
V_48 &= V_52 ;
return F_14 ( V_23 , V_47 , V_45 , V_48 ) ;
}
int F_15 ( struct V_39 * V_40 ,
struct V_38 * V_38 , void * V_53 , T_2 V_54 ,
enum V_55 V_34 )
{
const char * V_26 = L_3 ;
struct V_23 * V_23 = F_11 ( V_38 ) ;
const char * V_24 = V_38 -> V_56 . V_57 -> V_58 . V_28 ;
int V_11 = 0 ;
struct {
struct V_29 V_30 ;
char V_31 [ V_59 ] ;
} V_33 ;
if ( ! ( V_40 -> V_48 & V_60 ) ) {
T_3 V_61 = F_11 ( V_38 ) -> V_61 ;
if ( V_38 -> V_62 & V_63 ) {
V_26 = L_4 ;
V_11 = - V_64 ;
goto V_20;
}
V_33 . V_30 . V_34 = V_34 ;
V_11 = ( ! V_53 ) ? F_16 ( V_38 , & V_33 . V_30 ) :
F_17 ( V_53 , V_54 , & V_33 . V_30 ) ;
if ( ! V_11 ) {
int V_37 = sizeof( V_33 . V_30 ) + V_33 . V_30 . V_37 ;
void * V_65 = F_18 ( V_40 -> V_66 , V_37 ,
V_13 ) ;
if ( V_65 ) {
V_40 -> V_66 = V_65 ;
memcpy ( V_40 -> V_66 , & V_33 , V_37 ) ;
V_40 -> V_67 = V_61 ;
V_40 -> V_48 |= V_60 ;
} else
V_11 = - V_14 ;
}
}
V_20:
if ( V_11 )
F_8 ( V_68 , V_23 ,
V_24 , L_5 , V_26 ,
V_11 , 0 ) ;
return V_11 ;
}
void F_19 ( struct V_39 * V_40 ,
struct V_38 * V_38 , const unsigned char * V_24 ,
struct V_69 * V_70 ,
int V_71 )
{
static const char V_25 [] = L_1 ;
static const char V_26 [] = L_6 ;
int V_11 = - V_14 ;
struct V_23 * V_23 = F_11 ( V_38 ) ;
struct V_1 * V_2 ;
struct V_8 V_9 = { V_40 , V_38 , V_24 , V_70 ,
V_71 , NULL } ;
int V_22 = 0 ;
if ( V_40 -> V_48 & V_72 )
return;
V_11 = F_3 ( & V_9 , & V_2 ) ;
if ( V_11 < 0 ) {
F_8 ( V_36 , V_23 , V_24 ,
V_25 , V_26 , V_11 , 0 ) ;
return;
}
V_11 = F_6 ( V_2 , V_22 , V_23 , V_24 ) ;
if ( ! V_11 || V_11 == - V_73 )
V_40 -> V_48 |= V_72 ;
if ( V_11 < 0 )
F_1 ( V_2 ) ;
}
void F_20 ( struct V_39 * V_40 ,
const unsigned char * V_24 )
{
struct V_74 * V_75 ;
char V_33 [ ( V_40 -> V_66 -> V_37 * 2 ) + 1 ] ;
const char * V_76 = V_77 [ V_40 -> V_66 -> V_34 ] ;
char V_78 [ sizeof( V_33 ) + strlen ( V_76 ) + 2 ] ;
int V_3 ;
if ( V_40 -> V_48 & V_79 )
return;
for ( V_3 = 0 ; V_3 < V_40 -> V_66 -> V_37 ; V_3 ++ )
F_21 ( V_33 + ( V_3 * 2 ) , V_40 -> V_66 -> V_31 [ V_3 ] ) ;
V_33 [ V_3 * 2 ] = '\0' ;
V_75 = F_22 ( V_80 -> V_81 , V_82 ,
V_83 ) ;
if ( ! V_75 )
return;
F_23 ( V_75 , L_7 ) ;
F_24 ( V_75 , V_24 ) ;
F_23 ( V_75 , L_8 ) ;
snprintf ( V_78 , sizeof( V_78 ) , L_9 , V_76 , V_33 ) ;
F_24 ( V_75 , V_78 ) ;
F_25 ( V_75 , V_80 ) ;
F_26 ( V_75 ) ;
V_40 -> V_48 |= V_79 ;
}
const char * F_27 ( const struct V_84 * V_84 , char * * V_85 )
{
char * V_86 = NULL ;
* V_85 = F_28 () ;
if ( * V_85 ) {
V_86 = F_29 ( V_84 , * V_85 , V_87 ) ;
if ( F_30 ( V_86 ) ) {
F_31 ( * V_85 ) ;
* V_85 = NULL ;
V_86 = NULL ;
}
}
return V_86 ? : ( const char * ) V_84 -> V_57 -> V_58 . V_28 ;
}
