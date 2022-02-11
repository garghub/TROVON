void *
F_1 ( T_1 V_1 , T_2 V_2 , void * * V_3 )
{
* V_3 = F_2 ( V_1 , V_2 ) ;
if ( * V_3 == NULL )
return NULL ;
if ( ( V_4 ) * V_3 == F_3 ( ( V_4 ) * V_3 ) )
return * V_3 ;
F_4 ( * V_3 ) ;
* V_3 = F_2 ( V_1 + V_5 , V_2 ) ;
if ( * V_3 == NULL )
return NULL ;
return ( void * ) F_3 ( ( V_4 ) * V_3 ) ;
}
static unsigned long
F_5 ( int V_6 )
{
enum V_7 V_8 ;
V_4 V_9 = 0 ;
unsigned long V_10 = V_6 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
void * V_13 = V_13 ;
void * V_14 = NULL ;
enum V_7 (* F_6)
( void * , V_4 * , unsigned long * , T_1 * ) =
V_15 . F_6 ;
while ( 1 ) {
V_8 = F_6 ( V_13 , & V_9 , & V_10 , & V_11 ) ;
F_7 ( V_16 , L_1
L_2 , V_8 ,
( unsigned long ) V_9 , V_10 , V_11 ) ;
if ( V_8 != V_17 )
break;
if ( F_8 () )
V_11 = F_3 ( V_11 ) ;
if ( V_11 > V_12 ) {
if ( V_14 != NULL )
F_4 ( V_14 ) ;
V_12 = F_3 ( V_11 ) ;
V_13 = F_1 ( V_12 , V_18 ,
& V_14 ) ;
if ( V_14 == NULL ) {
F_9 ( V_16 , L_3
L_4 , V_12 ) ;
V_8 = V_19 ;
break;
}
}
V_8 = F_10 ( F_11 ( V_13 ) , V_10 , V_11 ) ;
if ( V_8 != V_20 ) {
F_7 ( V_16 , L_5 , V_8 ) ;
break;
}
}
F_4 ( V_14 ) ;
if ( V_8 != V_20 )
V_10 = 0 ;
F_7 ( V_16 , L_6 , V_10 ) ;
return V_10 ;
}
int
F_12 ( void )
{
int V_8 ;
struct V_21 * V_22 ;
unsigned long V_10 ;
unsigned long V_23 ;
F_13 () ;
V_10 = F_5 ( F_14 ( F_15 () ) ) ;
F_16 () ;
if ( V_10 == 0 ) {
F_9 ( V_16 , L_7 ) ;
return - V_24 ;
}
V_22 = (struct V_21 * ) F_17 ( F_18 ( V_10 ) ) ;
if ( V_22 -> V_25 < 3 ) {
V_22 -> V_26 &= 0xff ;
}
F_19 ( V_22 -> V_26 != V_27 ) ;
if ( V_22 -> V_26 < 0 || V_22 -> V_26 >= V_28 ) {
F_9 ( V_16 , L_8
L_9 , V_22 -> V_26 ,
V_28 ) ;
return - V_29 ;
}
V_22 -> V_30 = V_31 ;
V_22 -> V_32 = V_28 ;
if ( V_22 -> V_25 == 1 ) {
V_22 -> V_33 = 128 ;
}
V_34 = V_22 -> V_33 ;
V_35 = F_20 ( V_22 -> V_33 *
V_36 ) ;
V_37 = F_21 ( V_22 ) ;
V_38 = F_22 ( V_22 ) ;
V_8 = V_15 . V_39 ( V_22 ) ;
if ( V_8 != 0 )
return V_8 ;
V_23 = V_40 ;
if ( V_23 == 0 || V_23 == V_22 -> V_41 )
V_23 ++ ;
V_22 -> V_41 = V_23 ;
V_21 = V_22 ;
return 0 ;
}
void
F_23 ( void )
{
V_21 -> V_41 = 0 ;
}
enum V_7
F_24 ( int V_6 , unsigned long * V_42 ,
struct V_21 * V_43 , unsigned long * V_44 )
{
int V_45 ;
enum V_7 V_8 ;
* V_44 = F_5 ( V_6 ) ;
if ( * V_44 == 0 )
return V_46 ;
V_8 = F_10 ( F_11 ( V_43 ) , * V_44 ,
V_47 + V_34 ) ;
if ( V_8 != V_20 )
return V_8 ;
if ( V_42 != NULL ) {
unsigned long * V_48 =
F_21 ( V_43 ) ;
for ( V_45 = 0 ; V_45 < V_35 ; V_45 ++ )
V_42 [ V_45 ] |= V_48 [ V_45 ] ;
}
if ( V_43 -> V_41 == 0 )
return V_49 ;
if ( F_25 ( V_43 -> V_30 ) !=
F_25 ( V_31 ) ) {
return V_50 ;
}
if ( V_43 -> V_26 < 0 ||
V_43 -> V_26 >= V_28 ||
V_43 -> V_32 <= V_27 ) {
return V_51 ;
}
if ( V_43 -> V_26 == V_27 )
return V_52 ;
return V_20 ;
}
int
F_26 ( struct V_53 * V_54 )
{
short V_55 = F_27 ( V_54 ) ;
int V_56 ;
V_56 = ! V_15 . V_57 ( V_55 ) ;
if ( V_54 -> V_58 ) {
if ( ! V_56 ) {
if ( F_28 ( V_54 -> V_58 ) ) {
return 0 ;
}
F_29 ( V_16 , L_10
L_11 , V_55 ) ;
V_59 = 1 ;
V_15 . V_60 ( V_55 ) ;
V_56 = 1 ;
}
V_54 -> V_58 = 0 ;
if ( ! F_30 () )
F_31 ( & V_54 -> V_61 ) ;
F_32 ( V_54 -> V_62 != V_63 &&
V_54 -> V_62 != V_64 ) ;
if ( V_54 -> V_62 != V_64 )
F_33 ( V_54 ) ;
V_15 . V_65 ( V_54 ) ;
}
return V_56 ;
}
enum V_7
F_34 ( struct V_53 * V_54 )
{
unsigned long V_66 ;
enum V_7 V_8 ;
F_7 ( V_16 , L_12 , F_27 ( V_54 ) ) ;
F_35 ( & V_54 -> V_67 , V_66 ) ;
if ( V_54 -> V_62 == V_68 ) {
V_54 -> V_62 = V_69 ;
V_8 = V_20 ;
} else {
F_32 ( V_54 -> V_70 == V_20 ) ;
V_8 = V_54 -> V_70 ;
}
F_36 ( & V_54 -> V_67 , V_66 ) ;
return V_8 ;
}
void
F_37 ( const int line , struct V_53 * V_54 ,
enum V_7 V_70 )
{
unsigned long V_66 ;
F_35 ( & V_54 -> V_67 , V_66 ) ;
if ( V_54 -> V_62 == V_64 ) {
F_38 ( V_54 , V_70 , line ) ;
F_36 ( & V_54 -> V_67 , V_66 ) ;
if ( V_70 == V_71 ) {
V_15 . V_72 ( V_54 ) ;
}
return;
}
if ( V_54 -> V_62 == V_63 ) {
if ( ( V_54 -> V_70 == V_73 && V_70 != V_73 ) ||
V_70 == V_71 ) {
F_38 ( V_54 , V_70 , line ) ;
}
F_36 ( & V_54 -> V_67 , V_66 ) ;
return;
}
V_54 -> V_62 = V_63 ;
F_38 ( V_54 , V_70 , line ) ;
F_36 ( & V_54 -> V_67 , V_66 ) ;
V_15 . V_74 ( V_54 ) ;
V_54 -> V_58 = V_40 + ( V_75 * V_76 ) ;
V_54 -> V_61 . V_77 = V_54 -> V_58 ;
F_39 ( & V_54 -> V_61 ) ;
F_7 ( V_16 , L_13 ,
F_27 ( V_54 ) , V_70 ) ;
F_40 ( V_54 , V_70 ) ;
}
void
F_41 ( struct V_53 * V_54 )
{
unsigned long V_66 ;
F_7 ( V_16 , L_14 ,
F_27 ( V_54 ) ) ;
F_35 ( & V_54 -> V_67 , V_66 ) ;
V_54 -> V_62 = V_64 ;
F_36 ( & V_54 -> V_67 , V_66 ) ;
V_54 -> V_44 = 0 ;
}
void
F_42 ( void )
{
void * V_78 ;
struct V_21 * V_43 ;
unsigned long V_44 ;
int V_79 ;
int V_80 ;
int V_81 ;
int V_6 ;
struct V_21 * V_22 ;
unsigned long * V_42 ;
enum V_7 V_8 ;
V_43 = F_1 ( V_47 +
V_34 ,
V_18 , & V_78 ) ;
if ( V_43 == NULL )
return;
V_42 = F_43 ( sizeof( long ) * V_35 ,
V_18 ) ;
if ( V_42 == NULL ) {
F_4 ( V_78 ) ;
return;
}
V_22 = (struct V_21 * ) V_21 ;
V_80 = V_82 ;
if ( F_44 () )
V_81 = 256 ;
else {
V_81 = 64 ;
switch ( V_80 ) {
case 128 :
V_81 *= 2 ;
case 64 :
V_81 *= 2 ;
case 32 :
V_81 *= 2 ;
V_80 = 16 ;
F_32 ( ! F_45 () ) ;
}
}
for ( V_79 = 0 ; V_79 < V_81 ; V_79 ++ ) {
if ( V_83 )
break;
F_7 ( V_16 , L_15 , V_79 ) ;
for ( V_6 = ( V_79 * V_80 * 2 ) ;
V_6 < ( ( V_79 + 1 ) * V_80 * 2 ) ; V_6 += 2 ) {
if ( V_83 )
break;
F_7 ( V_16 , L_16 , V_6 ) ;
if ( F_46 ( V_6 / 2 , V_37 ) ) {
F_7 ( V_16 , L_17
L_18
L_19 , V_6 ) ;
break;
}
if ( ! ( F_46 ( V_6 / 2 , V_38 ) ) ) {
F_7 ( V_16 , L_20
L_21 ,
V_6 ) ;
continue;
}
if ( F_46 ( V_6 / 2 , V_42 ) ) {
F_7 ( V_16 , L_22
L_23
L_24 , V_6 ) ;
continue;
}
V_8 = F_24 ( V_6 , V_42 ,
V_43 , & V_44 ) ;
if ( V_8 != V_20 ) {
F_7 ( V_16 , L_25
L_26 , V_6 ,
V_8 ) ;
if ( V_8 == V_52 )
break;
continue;
}
V_15 . V_84 ( V_43 ,
V_44 , V_6 ) ;
}
}
F_4 ( V_42 ) ;
F_4 ( V_78 ) ;
}
enum V_7
F_47 ( short V_55 , void * V_85 )
{
struct V_53 * V_54 ;
unsigned long V_86 ;
V_54 = & V_87 [ V_55 ] ;
if ( V_54 -> V_44 == 0 )
return V_88 ;
memset ( V_85 , 0 , V_34 ) ;
V_86 = ( unsigned long ) F_21 ( V_54 -> V_44 ) ;
return F_10 ( F_11 ( V_85 ) , V_86 ,
V_34 ) ;
}
