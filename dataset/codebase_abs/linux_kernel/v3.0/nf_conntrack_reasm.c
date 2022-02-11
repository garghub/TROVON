static unsigned int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
return F_3 ( V_4 -> V_5 , & V_4 -> V_6 , & V_4 -> V_7 , V_8 . V_9 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
if ( F_5 ( V_11 ) -> V_12 )
F_6 ( F_5 ( V_11 ) -> V_12 ) ;
}
static T_1 void F_7 ( struct V_3 * V_13 )
{
F_8 ( & V_13 -> V_2 , & V_8 ) ;
}
static T_1 void F_9 ( struct V_3 * V_13 )
{
F_10 ( & V_13 -> V_2 , & V_8 ) ;
}
static void F_11 ( void )
{
F_12 () ;
F_13 ( & V_14 , & V_8 ) ;
F_14 () ;
}
static void F_15 ( unsigned long V_15 )
{
struct V_3 * V_13 ;
V_13 = F_2 ( (struct V_1 * ) V_15 ,
struct V_3 , V_2 ) ;
F_16 ( & V_13 -> V_2 . V_16 ) ;
if ( V_13 -> V_2 . V_17 & V_18 )
goto V_19;
F_9 ( V_13 ) ;
V_19:
F_17 ( & V_13 -> V_2 . V_16 ) ;
F_7 ( V_13 ) ;
}
int V_3 ( struct V_3 * V_13 , struct V_10 * V_11 ,
const struct V_20 * V_21 , int V_22 )
{
struct V_10 * V_23 , * V_24 ;
int V_25 , V_26 ;
if ( V_13 -> V_2 . V_17 & V_18 ) {
F_18 ( L_1 ) ;
goto V_27;
}
V_25 = F_19 ( V_21 -> V_28 ) & ~ 0x7 ;
V_26 = V_25 + ( F_19 ( F_20 ( V_11 ) -> V_29 ) -
( ( V_30 * ) ( V_21 + 1 ) - ( V_30 * ) ( F_20 ( V_11 ) + 1 ) ) ) ;
if ( ( unsigned int ) V_26 > V_31 ) {
F_18 ( L_2 ) ;
return - 1 ;
}
if ( V_11 -> V_32 == V_33 ) {
const unsigned char * V_34 = F_21 ( V_11 ) ;
V_11 -> V_35 = F_22 ( V_11 -> V_35 ,
F_23 ( V_34 , ( V_30 * ) ( V_21 + 1 ) - V_34 ,
0 ) ) ;
}
if ( ! ( V_21 -> V_28 & F_24 ( V_36 ) ) ) {
if ( V_26 < V_13 -> V_2 . V_37 ||
( ( V_13 -> V_2 . V_17 & V_38 ) && V_26 != V_13 -> V_2 . V_37 ) ) {
F_18 ( L_3 ) ;
goto V_27;
}
V_13 -> V_2 . V_17 |= V_38 ;
V_13 -> V_2 . V_37 = V_26 ;
} else {
if ( V_26 & 0x7 ) {
F_18 ( L_4 ) ;
return - 1 ;
}
if ( V_26 > V_13 -> V_2 . V_37 ) {
if ( V_13 -> V_2 . V_17 & V_38 ) {
F_18 ( L_5 ) ;
goto V_27;
}
V_13 -> V_2 . V_37 = V_26 ;
}
}
if ( V_26 == V_25 )
goto V_27;
if ( ! F_25 ( V_11 , ( V_30 * ) ( V_21 + 1 ) - V_11 -> V_15 ) ) {
F_18 ( L_6 ) ;
goto V_27;
}
if ( F_26 ( V_11 , V_26 - V_25 ) ) {
F_18 ( L_7 ) ;
goto V_27;
}
V_23 = V_13 -> V_2 . V_39 ;
if ( ! V_23 || F_5 ( V_23 ) -> V_25 < V_25 ) {
V_24 = NULL ;
goto V_40;
}
V_23 = NULL ;
for ( V_24 = V_13 -> V_2 . V_41 ; V_24 != NULL ; V_24 = V_24 -> V_24 ) {
if ( F_5 ( V_24 ) -> V_25 >= V_25 )
break;
V_23 = V_24 ;
}
V_40:
if ( V_23 &&
( F_5 ( V_23 ) -> V_25 + V_23 -> V_37 ) > V_25 )
goto V_42;
if ( V_24 && F_5 ( V_24 ) -> V_25 < V_26 )
goto V_42;
F_5 ( V_11 ) -> V_25 = V_25 ;
V_11 -> V_24 = V_24 ;
if ( ! V_24 )
V_13 -> V_2 . V_39 = V_11 ;
if ( V_23 )
V_23 -> V_24 = V_11 ;
else
V_13 -> V_2 . V_41 = V_11 ;
V_11 -> V_43 = NULL ;
V_13 -> V_2 . V_44 = V_11 -> V_45 ;
V_13 -> V_2 . V_46 += V_11 -> V_37 ;
F_27 ( V_11 -> V_47 , & V_14 . V_48 ) ;
if ( V_25 == 0 ) {
V_13 -> V_49 = V_22 ;
V_13 -> V_2 . V_17 |= V_50 ;
}
F_28 ( & V_8 . V_16 ) ;
F_29 ( & V_13 -> V_2 . V_51 , & V_14 . V_51 ) ;
F_30 ( & V_8 . V_16 ) ;
return 0 ;
V_42:
F_9 ( V_13 ) ;
V_27:
return - 1 ;
}
static struct V_10 *
F_31 ( struct V_3 * V_13 , struct V_52 * V_43 )
{
struct V_10 * V_53 , * V_54 , * V_55 = V_13 -> V_2 . V_41 ;
int V_29 ;
F_9 ( V_13 ) ;
F_32 ( V_55 == NULL ) ;
F_32 ( F_5 ( V_55 ) -> V_25 != 0 ) ;
V_29 = ( ( V_55 -> V_15 - F_21 ( V_55 ) ) -
sizeof( struct V_56 ) + V_13 -> V_2 . V_37 -
sizeof( struct V_20 ) ) ;
if ( V_29 > V_31 ) {
F_18 ( L_8 ) ;
goto V_57;
}
if ( F_33 ( V_55 ) && F_34 ( V_55 , 0 , 0 , V_58 ) ) {
F_18 ( L_9 ) ;
goto V_59;
}
if ( F_35 ( V_55 ) ) {
struct V_10 * V_60 ;
int V_61 , V_62 = 0 ;
if ( ( V_60 = F_36 ( 0 , V_58 ) ) == NULL ) {
F_18 ( L_10 ) ;
goto V_59;
}
V_60 -> V_24 = V_55 -> V_24 ;
V_55 -> V_24 = V_60 ;
F_37 ( V_60 ) -> V_63 = F_37 ( V_55 ) -> V_63 ;
F_38 ( V_55 ) ;
for ( V_61 = 0 ; V_61 < F_37 ( V_55 ) -> V_64 ; V_61 ++ )
V_62 += F_37 ( V_55 ) -> V_65 [ V_61 ] . V_66 ;
V_60 -> V_37 = V_60 -> V_67 = V_55 -> V_67 - V_62 ;
V_55 -> V_67 -= V_60 -> V_37 ;
V_55 -> V_37 -= V_60 -> V_37 ;
V_60 -> V_35 = 0 ;
V_60 -> V_32 = V_55 -> V_32 ;
F_5 ( V_60 ) -> V_12 = NULL ;
F_27 ( V_60 -> V_47 , & V_14 . V_48 ) ;
}
F_21 ( V_55 ) [ V_13 -> V_49 ] = F_39 ( V_55 ) [ 0 ] ;
memmove ( V_55 -> V_55 + sizeof( struct V_20 ) , V_55 -> V_55 ,
( V_55 -> V_15 - V_55 -> V_55 ) - sizeof( struct V_20 ) ) ;
V_55 -> V_68 += sizeof( struct V_20 ) ;
V_55 -> V_69 += sizeof( struct V_20 ) ;
F_37 ( V_55 ) -> V_63 = V_55 -> V_24 ;
F_40 ( V_55 ) ;
F_41 ( V_55 , V_55 -> V_15 - F_21 ( V_55 ) ) ;
for ( V_53 = V_55 -> V_24 ; V_53 ; V_53 = V_53 -> V_24 ) {
V_55 -> V_67 += V_53 -> V_37 ;
V_55 -> V_37 += V_53 -> V_37 ;
if ( V_55 -> V_32 != V_53 -> V_32 )
V_55 -> V_32 = V_70 ;
else if ( V_55 -> V_32 == V_33 )
V_55 -> V_35 = F_42 ( V_55 -> V_35 , V_53 -> V_35 ) ;
V_55 -> V_47 += V_53 -> V_47 ;
}
F_43 ( V_55 -> V_47 , & V_14 . V_48 ) ;
V_55 -> V_24 = NULL ;
V_55 -> V_43 = V_43 ;
V_55 -> V_45 = V_13 -> V_2 . V_44 ;
F_20 ( V_55 ) -> V_29 = F_24 ( V_29 ) ;
if ( V_55 -> V_32 == V_33 )
V_55 -> V_35 = F_23 ( F_21 ( V_55 ) ,
F_44 ( V_55 ) ,
V_55 -> V_35 ) ;
V_13 -> V_2 . V_41 = NULL ;
V_13 -> V_2 . V_39 = NULL ;
V_53 = F_37 ( V_55 ) -> V_63 ;
if ( V_53 && F_5 ( V_53 ) -> V_12 == NULL )
V_53 = V_53 -> V_24 ;
V_54 = F_5 ( V_55 ) -> V_12 ;
for (; V_53 ; V_53 = V_53 -> V_24 ) {
struct V_10 * V_12 = F_5 ( V_53 ) -> V_12 ;
V_54 -> V_24 = V_12 ;
V_54 = V_12 ;
F_5 ( V_53 ) -> V_12 = NULL ;
}
return V_55 ;
V_57:
if ( F_45 () )
F_46 ( V_71 L_11 , V_29 ) ;
goto V_72;
V_59:
if ( F_45 () )
F_46 ( V_71 L_12 ) ;
V_72:
return NULL ;
}
static int
F_47 ( struct V_10 * V_11 , V_30 * V_73 , int * V_74 , int * V_75 )
{
V_30 V_76 = F_20 ( V_11 ) -> V_76 ;
const int V_77 = F_48 ( V_11 ) ;
V_30 V_78 = V_77 + F_49 ( struct V_56 , V_76 ) ;
int V_79 = V_77 + sizeof( struct V_56 ) ;
int V_37 = V_11 -> V_37 - V_79 ;
V_30 V_80 = V_81 ;
while ( V_76 != V_82 ) {
struct V_83 V_84 ;
int V_85 ;
if ( ! F_50 ( V_76 ) ) {
return - 1 ;
}
if ( V_76 == V_86 ) {
F_18 ( L_13 ) ;
return - 1 ;
}
if ( V_37 < ( int ) sizeof( struct V_83 ) ) {
F_18 ( L_14 ) ;
return - 1 ;
}
if ( F_51 ( V_11 , V_79 , & V_84 , sizeof( V_84 ) ) )
F_52 () ;
if ( V_76 == V_87 )
V_85 = ( V_84 . V_85 + 2 ) << 2 ;
else
V_85 = F_53 ( & V_84 ) ;
V_80 = V_76 ;
V_78 = V_79 ;
V_76 = V_84 . V_76 ;
V_37 -= V_85 ;
V_79 += V_85 ;
}
if ( V_37 < 0 )
return - 1 ;
* V_73 = V_80 ;
* V_74 = V_78 ;
* V_75 = V_79 ;
return 0 ;
}
struct V_10 * F_54 ( struct V_10 * V_11 , T_2 V_88 )
{
struct V_10 * V_60 ;
struct V_52 * V_43 = V_11 -> V_43 ;
struct V_20 * V_21 ;
struct V_3 * V_13 ;
struct V_56 * V_84 ;
int V_75 , V_22 ;
V_30 V_80 ;
struct V_10 * V_89 = NULL ;
if ( F_20 ( V_11 ) -> V_29 == 0 ) {
F_18 ( L_15 ) ;
return V_11 ;
}
if ( F_47 ( V_11 , & V_80 , & V_22 , & V_75 ) < 0 )
return V_11 ;
V_60 = F_55 ( V_11 , V_58 ) ;
if ( V_60 == NULL ) {
F_18 ( L_16 ) ;
return V_11 ;
}
F_5 ( V_60 ) -> V_12 = V_11 ;
if ( ! F_56 ( V_60 , V_75 + sizeof( * V_21 ) ) ) {
F_18 ( L_17 ) ;
goto V_90;
}
F_57 ( V_60 , V_75 ) ;
V_84 = F_20 ( V_60 ) ;
V_21 = (struct V_20 * ) F_39 ( V_60 ) ;
if ( F_58 ( & V_14 . V_48 ) > V_14 . V_91 )
F_11 () ;
V_13 = F_59 ( V_21 -> V_92 , V_88 , & V_84 -> V_6 , & V_84 -> V_7 ) ;
if ( V_13 == NULL ) {
F_18 ( L_18 ) ;
goto V_90;
}
F_60 ( & V_13 -> V_2 . V_16 ) ;
if ( V_3 ( V_13 , V_60 , V_21 , V_22 ) < 0 ) {
F_61 ( & V_13 -> V_2 . V_16 ) ;
F_18 ( L_19 ) ;
F_7 ( V_13 ) ;
goto V_90;
}
if ( V_13 -> V_2 . V_17 == ( V_50 | V_38 ) &&
V_13 -> V_2 . V_46 == V_13 -> V_2 . V_37 ) {
V_89 = F_31 ( V_13 , V_43 ) ;
if ( V_89 == NULL )
F_18 ( L_20 ) ;
}
F_61 ( & V_13 -> V_2 . V_16 ) ;
F_7 ( V_13 ) ;
return V_89 ;
V_90:
F_6 ( V_60 ) ;
return V_11 ;
}
void F_62 ( unsigned int V_93 , struct V_10 * V_11 ,
struct V_52 * V_94 , struct V_52 * V_19 ,
int (* F_63)( struct V_10 * ) )
{
struct V_10 * V_95 , * V_96 ;
for ( V_95 = F_5 ( V_11 ) -> V_12 ; V_95 ; ) {
F_64 ( V_95 -> V_97 ) ;
F_65 ( V_11 ) ;
V_95 -> V_97 = V_11 ;
V_96 = V_95 -> V_24 ;
V_95 -> V_24 = NULL ;
F_66 ( V_98 , V_93 , V_95 , V_94 , V_19 , F_63 ,
V_99 + 1 ) ;
V_95 = V_96 ;
}
F_64 ( V_11 ) ;
}
int F_67 ( void )
{
V_8 . V_100 = F_1 ;
V_8 . V_101 = V_102 ;
V_8 . V_103 = NULL ;
V_8 . V_104 = F_4 ;
V_8 . V_105 = sizeof( struct V_3 ) ;
V_8 . V_106 = V_107 ;
V_8 . V_108 = F_15 ;
V_8 . V_109 = 10 * 60 * V_110 ;
V_14 . V_111 = V_112 ;
V_14 . V_91 = V_113 ;
V_14 . V_114 = V_115 ;
F_68 ( & V_14 ) ;
F_69 ( & V_8 ) ;
#ifdef F_70
V_116 = F_71 ( V_117 ,
V_118 ) ;
if ( ! V_116 ) {
F_72 ( & V_8 ) ;
return - V_119 ;
}
#endif
return 0 ;
}
void F_73 ( void )
{
#ifdef F_70
F_74 ( V_116 ) ;
V_116 = NULL ;
#endif
F_72 ( & V_8 ) ;
V_14 . V_114 = 0 ;
F_11 () ;
}
