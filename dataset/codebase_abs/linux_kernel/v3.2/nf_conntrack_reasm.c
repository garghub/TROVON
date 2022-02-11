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
V_60 = F_36 ( 0 , V_58 ) ;
if ( V_60 == NULL )
goto V_59;
V_60 -> V_24 = V_55 -> V_24 ;
V_55 -> V_24 = V_60 ;
F_37 ( V_60 ) -> V_63 = F_37 ( V_55 ) -> V_63 ;
F_38 ( V_55 ) ;
for ( V_61 = 0 ; V_61 < F_37 ( V_55 ) -> V_64 ; V_61 ++ )
V_62 += F_39 ( & F_37 ( V_55 ) -> V_65 [ V_61 ] ) ;
V_60 -> V_37 = V_60 -> V_66 = V_55 -> V_66 - V_62 ;
V_55 -> V_66 -= V_60 -> V_37 ;
V_55 -> V_37 -= V_60 -> V_37 ;
V_60 -> V_35 = 0 ;
V_60 -> V_32 = V_55 -> V_32 ;
F_5 ( V_60 ) -> V_12 = NULL ;
F_27 ( V_60 -> V_47 , & V_14 . V_48 ) ;
}
F_21 ( V_55 ) [ V_13 -> V_49 ] = F_40 ( V_55 ) [ 0 ] ;
memmove ( V_55 -> V_55 + sizeof( struct V_20 ) , V_55 -> V_55 ,
( V_55 -> V_15 - V_55 -> V_55 ) - sizeof( struct V_20 ) ) ;
V_55 -> V_67 += sizeof( struct V_20 ) ;
V_55 -> V_68 += sizeof( struct V_20 ) ;
F_37 ( V_55 ) -> V_63 = V_55 -> V_24 ;
F_41 ( V_55 ) ;
F_42 ( V_55 , V_55 -> V_15 - F_21 ( V_55 ) ) ;
for ( V_53 = V_55 -> V_24 ; V_53 ; V_53 = V_53 -> V_24 ) {
V_55 -> V_66 += V_53 -> V_37 ;
V_55 -> V_37 += V_53 -> V_37 ;
if ( V_55 -> V_32 != V_53 -> V_32 )
V_55 -> V_32 = V_69 ;
else if ( V_55 -> V_32 == V_33 )
V_55 -> V_35 = F_43 ( V_55 -> V_35 , V_53 -> V_35 ) ;
V_55 -> V_47 += V_53 -> V_47 ;
}
F_44 ( V_55 -> V_47 , & V_14 . V_48 ) ;
V_55 -> V_24 = NULL ;
V_55 -> V_43 = V_43 ;
V_55 -> V_45 = V_13 -> V_2 . V_44 ;
F_20 ( V_55 ) -> V_29 = F_24 ( V_29 ) ;
if ( V_55 -> V_32 == V_33 )
V_55 -> V_35 = F_23 ( F_21 ( V_55 ) ,
F_45 ( V_55 ) ,
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
if ( F_46 () )
F_47 ( V_70 L_10 , V_29 ) ;
goto V_71;
V_59:
if ( F_46 () )
F_47 ( V_70 L_11 ) ;
V_71:
return NULL ;
}
static int
F_48 ( struct V_10 * V_11 , V_30 * V_72 , int * V_73 , int * V_74 )
{
V_30 V_75 = F_20 ( V_11 ) -> V_75 ;
const int V_76 = F_49 ( V_11 ) ;
V_30 V_77 = V_76 + F_50 ( struct V_56 , V_75 ) ;
int V_78 = V_76 + sizeof( struct V_56 ) ;
int V_37 = V_11 -> V_37 - V_78 ;
V_30 V_79 = V_80 ;
while ( V_75 != V_81 ) {
struct V_82 V_83 ;
int V_84 ;
if ( ! F_51 ( V_75 ) ) {
return - 1 ;
}
if ( V_75 == V_85 ) {
F_18 ( L_12 ) ;
return - 1 ;
}
if ( V_37 < ( int ) sizeof( struct V_82 ) ) {
F_18 ( L_13 ) ;
return - 1 ;
}
if ( F_52 ( V_11 , V_78 , & V_83 , sizeof( V_83 ) ) )
F_53 () ;
if ( V_75 == V_86 )
V_84 = ( V_83 . V_84 + 2 ) << 2 ;
else
V_84 = F_54 ( & V_83 ) ;
V_79 = V_75 ;
V_77 = V_78 ;
V_75 = V_83 . V_75 ;
V_37 -= V_84 ;
V_78 += V_84 ;
}
if ( V_37 < 0 )
return - 1 ;
* V_72 = V_79 ;
* V_73 = V_77 ;
* V_74 = V_78 ;
return 0 ;
}
struct V_10 * F_55 ( struct V_10 * V_11 , T_2 V_87 )
{
struct V_10 * V_60 ;
struct V_52 * V_43 = V_11 -> V_43 ;
struct V_20 * V_21 ;
struct V_3 * V_13 ;
struct V_56 * V_83 ;
int V_74 , V_22 ;
V_30 V_79 ;
struct V_10 * V_88 = NULL ;
if ( F_20 ( V_11 ) -> V_29 == 0 ) {
F_18 ( L_14 ) ;
return V_11 ;
}
if ( F_48 ( V_11 , & V_79 , & V_22 , & V_74 ) < 0 )
return V_11 ;
V_60 = F_56 ( V_11 , V_58 ) ;
if ( V_60 == NULL ) {
F_18 ( L_15 ) ;
return V_11 ;
}
F_5 ( V_60 ) -> V_12 = V_11 ;
if ( ! F_57 ( V_60 , V_74 + sizeof( * V_21 ) ) ) {
F_18 ( L_16 ) ;
goto V_89;
}
F_58 ( V_60 , V_74 ) ;
V_83 = F_20 ( V_60 ) ;
V_21 = (struct V_20 * ) F_40 ( V_60 ) ;
if ( F_59 ( & V_14 . V_48 ) > V_14 . V_90 )
F_11 () ;
V_13 = F_60 ( V_21 -> V_91 , V_87 , & V_83 -> V_6 , & V_83 -> V_7 ) ;
if ( V_13 == NULL ) {
F_18 ( L_17 ) ;
goto V_89;
}
F_61 ( & V_13 -> V_2 . V_16 ) ;
if ( V_3 ( V_13 , V_60 , V_21 , V_22 ) < 0 ) {
F_62 ( & V_13 -> V_2 . V_16 ) ;
F_18 ( L_18 ) ;
F_7 ( V_13 ) ;
goto V_89;
}
if ( V_13 -> V_2 . V_17 == ( V_50 | V_38 ) &&
V_13 -> V_2 . V_46 == V_13 -> V_2 . V_37 ) {
V_88 = F_31 ( V_13 , V_43 ) ;
if ( V_88 == NULL )
F_18 ( L_19 ) ;
}
F_62 ( & V_13 -> V_2 . V_16 ) ;
F_7 ( V_13 ) ;
return V_88 ;
V_89:
F_6 ( V_60 ) ;
return V_11 ;
}
void F_63 ( unsigned int V_92 , struct V_10 * V_11 ,
struct V_52 * V_93 , struct V_52 * V_19 ,
int (* F_64)( struct V_10 * ) )
{
struct V_10 * V_94 , * V_95 ;
for ( V_94 = F_5 ( V_11 ) -> V_12 ; V_94 ; ) {
F_65 ( V_94 -> V_96 ) ;
F_66 ( V_11 ) ;
V_94 -> V_96 = V_11 ;
V_95 = V_94 -> V_24 ;
V_94 -> V_24 = NULL ;
F_67 ( V_97 , V_92 , V_94 , V_93 , V_19 , F_64 ,
V_98 + 1 ) ;
V_94 = V_95 ;
}
F_65 ( V_11 ) ;
}
int F_68 ( void )
{
V_8 . V_99 = F_1 ;
V_8 . V_100 = V_101 ;
V_8 . V_102 = NULL ;
V_8 . V_103 = F_4 ;
V_8 . V_104 = sizeof( struct V_3 ) ;
V_8 . V_105 = V_106 ;
V_8 . V_107 = F_15 ;
V_8 . V_108 = 10 * 60 * V_109 ;
V_14 . V_110 = V_111 ;
V_14 . V_90 = V_112 ;
V_14 . V_113 = V_114 ;
F_69 ( & V_14 ) ;
F_70 ( & V_8 ) ;
#ifdef F_71
V_115 = F_72 ( V_116 ,
V_117 ) ;
if ( ! V_115 ) {
F_73 ( & V_8 ) ;
return - V_118 ;
}
#endif
return 0 ;
}
void F_74 ( void )
{
#ifdef F_71
F_75 ( V_115 ) ;
V_115 = NULL ;
#endif
F_73 ( & V_8 ) ;
V_14 . V_113 = 0 ;
F_11 () ;
}
