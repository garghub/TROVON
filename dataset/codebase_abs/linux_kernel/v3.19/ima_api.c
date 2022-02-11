void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 -> V_5 ; V_3 ++ )
F_2 ( V_2 -> V_6 [ V_3 ] . V_7 ) ;
F_2 ( V_2 ) ;
}
int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_10 , const unsigned char * V_11 ,
struct V_12 * V_13 ,
int V_14 , struct V_1 * * V_2 )
{
struct V_15 * V_4 = F_4 () ;
int V_3 , V_16 = 0 ;
* V_2 = F_5 ( sizeof( * * V_2 ) + V_4 -> V_5 *
sizeof( struct V_17 ) , V_18 ) ;
if ( ! * V_2 )
return - V_19 ;
( * V_2 ) -> V_4 = V_4 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
struct V_20 * V_21 = V_4 -> V_22 [ V_3 ] ;
T_1 V_23 ;
V_16 = V_21 -> V_24 ( V_9 , V_10 , V_11 ,
V_13 , V_14 ,
& ( ( * V_2 ) -> V_6 [ V_3 ] ) ) ;
if ( V_16 != 0 )
goto V_25;
V_23 = ( * V_2 ) -> V_6 [ V_3 ] . V_23 ;
( * V_2 ) -> V_26 += sizeof( V_23 ) ;
( * V_2 ) -> V_26 += V_23 ;
}
return 0 ;
V_25:
F_1 ( * V_2 ) ;
* V_2 = NULL ;
return V_16 ;
}
int F_6 ( struct V_1 * V_2 ,
int V_27 , struct V_28 * V_28 ,
const unsigned char * V_11 )
{
static const char V_29 [] = L_1 ;
static const char V_30 [] = L_2 ;
char * V_31 = V_2 -> V_4 -> V_32 ;
int V_16 ;
struct {
struct V_33 V_34 ;
char V_35 [ V_36 ] ;
} V_37 ;
if ( ! V_27 ) {
int V_5 = V_2 -> V_4 -> V_5 ;
V_37 . V_34 . V_38 = V_39 ;
V_16 = F_7 ( & V_2 -> V_6 [ 0 ] ,
V_2 -> V_4 ,
V_5 , & V_37 . V_34 ) ;
if ( V_16 < 0 ) {
F_8 ( V_40 , V_28 ,
V_31 , V_29 ,
V_30 , V_16 , 0 ) ;
return V_16 ;
}
memcpy ( V_2 -> V_35 , V_37 . V_34 . V_35 , V_37 . V_34 . V_41 ) ;
}
V_16 = F_9 ( V_2 , V_27 , V_29 , V_28 , V_11 ) ;
return V_16 ;
}
void F_10 ( struct V_10 * V_10 , const unsigned char * V_11 ,
const char * V_29 , const char * V_42 )
{
struct V_1 * V_2 ;
struct V_28 * V_28 = F_11 ( V_10 ) ;
int V_27 = 1 ;
int V_16 ;
F_12 ( & V_43 . V_44 ) ;
V_16 = F_3 ( NULL , V_10 , V_11 ,
NULL , 0 , & V_2 ) ;
if ( V_16 < 0 ) {
V_16 = - V_19 ;
goto V_45;
}
V_16 = F_6 ( V_2 , V_27 , V_28 , V_11 ) ;
if ( V_16 < 0 )
F_1 ( V_2 ) ;
V_45:
F_8 ( V_40 , V_28 , V_11 ,
V_29 , V_42 , V_16 , 0 ) ;
}
int F_13 ( struct V_28 * V_28 , int V_46 , int V_47 )
{
int V_48 = V_49 | V_50 | V_51 ;
V_48 &= V_52 ;
return F_14 ( V_28 , V_47 , V_46 , V_48 ) ;
}
int F_15 ( struct V_8 * V_9 ,
struct V_10 * V_10 ,
struct V_12 * * V_13 ,
int * V_14 )
{
const char * V_30 = L_3 ;
struct V_28 * V_28 = F_11 ( V_10 ) ;
const char * V_11 = V_10 -> V_53 . V_54 -> V_55 . V_32 ;
int V_16 = 0 ;
struct {
struct V_33 V_34 ;
char V_35 [ V_56 ] ;
} V_37 ;
if ( V_13 )
* V_14 = F_16 ( V_10 -> V_53 . V_54 , V_13 ) ;
if ( ! ( V_9 -> V_48 & V_57 ) ) {
T_2 V_58 = F_11 ( V_10 ) -> V_58 ;
if ( V_10 -> V_59 & V_60 ) {
V_30 = L_4 ;
V_16 = - V_61 ;
goto V_25;
}
V_37 . V_34 . V_38 = V_62 ;
if ( V_13 )
F_17 ( * V_13 , * V_14 , & V_37 . V_34 ) ;
V_16 = F_18 ( V_10 , & V_37 . V_34 ) ;
if ( ! V_16 ) {
int V_41 = sizeof( V_37 . V_34 ) + V_37 . V_34 . V_41 ;
void * V_63 = F_19 ( V_9 -> V_64 , V_41 ,
V_18 ) ;
if ( V_63 ) {
V_9 -> V_64 = V_63 ;
memcpy ( V_9 -> V_64 , & V_37 , V_41 ) ;
V_9 -> V_65 = V_58 ;
V_9 -> V_48 |= V_57 ;
} else
V_16 = - V_19 ;
}
}
V_25:
if ( V_16 )
F_8 ( V_66 , V_28 ,
V_11 , L_5 , V_30 ,
V_16 , 0 ) ;
return V_16 ;
}
void F_20 ( struct V_8 * V_9 ,
struct V_10 * V_10 , const unsigned char * V_11 ,
struct V_12 * V_13 ,
int V_14 )
{
static const char V_29 [] = L_1 ;
static const char V_30 [] = L_6 ;
int V_16 = - V_19 ;
struct V_28 * V_28 = F_11 ( V_10 ) ;
struct V_1 * V_2 ;
int V_27 = 0 ;
if ( V_9 -> V_48 & V_67 )
return;
V_16 = F_3 ( V_9 , V_10 , V_11 ,
V_13 , V_14 , & V_2 ) ;
if ( V_16 < 0 ) {
F_8 ( V_40 , V_28 , V_11 ,
V_29 , V_30 , V_16 , 0 ) ;
return;
}
V_16 = F_6 ( V_2 , V_27 , V_28 , V_11 ) ;
if ( ! V_16 || V_16 == - V_68 )
V_9 -> V_48 |= V_67 ;
if ( V_16 < 0 )
F_1 ( V_2 ) ;
}
void F_21 ( struct V_8 * V_9 ,
const unsigned char * V_11 )
{
struct V_69 * V_70 ;
char V_37 [ ( V_9 -> V_64 -> V_41 * 2 ) + 1 ] ;
const char * V_71 = V_72 [ V_9 -> V_64 -> V_38 ] ;
char V_73 [ sizeof( V_37 ) + strlen ( V_71 ) + 2 ] ;
int V_3 ;
if ( V_9 -> V_48 & V_74 )
return;
for ( V_3 = 0 ; V_3 < V_9 -> V_64 -> V_41 ; V_3 ++ )
F_22 ( V_37 + ( V_3 * 2 ) , V_9 -> V_64 -> V_35 [ V_3 ] ) ;
V_37 [ V_3 * 2 ] = '\0' ;
V_70 = F_23 ( V_75 -> V_76 , V_77 ,
V_78 ) ;
if ( ! V_70 )
return;
F_24 ( V_70 , L_7 ) ;
F_25 ( V_70 , V_11 ) ;
F_24 ( V_70 , L_8 ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_9 , V_71 , V_37 ) ;
F_25 ( V_70 , V_73 ) ;
F_26 ( V_70 , V_75 ) ;
F_27 ( V_70 ) ;
V_9 -> V_48 |= V_74 ;
}
const char * F_28 ( struct V_79 * V_79 , char * * V_80 )
{
char * V_81 = NULL ;
* V_80 = F_29 () ;
if ( * V_80 ) {
V_81 = F_30 ( V_79 , * V_80 , V_82 ) ;
if ( F_31 ( V_81 ) ) {
F_32 ( * V_80 ) ;
* V_80 = NULL ;
V_81 = NULL ;
}
}
return V_81 ? : ( const char * ) V_79 -> V_54 -> V_55 . V_32 ;
}
