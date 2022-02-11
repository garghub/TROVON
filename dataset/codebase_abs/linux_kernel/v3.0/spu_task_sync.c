static void F_1 ( unsigned long int V_1 , int V_2 )
{
int V_3 = 1 ;
if ( V_4 [ V_2 ] . V_5 >= V_4 [ V_2 ] . V_6 ) {
if ( ( V_4 [ V_2 ] . V_5 - V_4 [ V_2 ] . V_6 )
< ( V_7 - 1 ) )
V_3 = 0 ;
} else if ( V_4 [ V_2 ] . V_6 > V_4 [ V_2 ] . V_5 ) {
if ( ( V_4 [ V_2 ] . V_6 - V_4 [ V_2 ] . V_5 )
> 1 )
V_3 = 0 ;
}
if ( ! V_3 ) {
V_4 [ V_2 ] . V_8 [ V_4 [ V_2 ] . V_5 ] = V_1 ;
V_4 [ V_2 ] . V_5 ++ ;
if ( V_4 [ V_2 ] . V_5 >= V_7 )
V_4 [ V_2 ] . V_5 = 0 ;
} else {
F_2 () ;
}
}
void F_3 ( void )
{
int V_2 ;
unsigned long V_9 ;
int V_10 ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
if ( V_4 [ V_2 ] . V_8 == NULL )
continue;
F_4 ( & V_12 , V_9 ) ;
V_10 = V_4 [ V_2 ] . V_5 ;
F_5 ( & V_12 , V_9 ) ;
F_6 ( V_4 [ V_2 ] . V_8 ,
V_4 [ V_2 ] . V_6 ,
V_10 , V_7 ) ;
F_4 ( & V_12 , V_9 ) ;
V_4 [ V_2 ] . V_6 = V_10 ;
F_5 ( & V_12 , V_9 ) ;
}
}
static void F_7 ( struct V_13 * V_14 )
{
F_3 () ;
if ( V_15 )
F_8 ( & V_16 , V_17 ) ;
}
static void F_9 ( struct V_18 * V_18 )
{
struct V_19 * V_20 ;
V_20 = F_10 ( V_18 , struct V_19 , V_21 ) ;
F_11 ( V_20 -> V_22 ) ;
F_12 ( V_20 ) ;
F_13 ( V_23 ) ;
}
static struct V_19 * F_14 ( struct V_2 * V_24 , int V_25 )
{
struct V_18 * V_26 ;
struct V_19 * V_27 ;
if ( V_25 >= V_11 ) {
F_15 ( V_28 L_1
L_2 ,
V_29 , __LINE__ , V_25 ) ;
V_27 = NULL ;
goto V_30;
}
if ( ! V_31 [ V_25 ] && V_24 ) {
V_26 = F_16 ( V_24 -> V_32 ) ;
if ( V_26 ) {
V_31 [ V_25 ] = F_10 ( V_26 , struct V_19 , V_21 ) ;
F_17 ( & V_31 [ V_25 ] -> V_21 ) ;
}
}
V_27 = V_31 [ V_25 ] ;
V_30:
return V_27 ;
}
static int
F_18 ( struct V_2 * V_2 , unsigned long V_33 )
{
unsigned long V_9 ;
struct V_34 * V_35 ;
int V_36 = 0 ;
struct V_19 * V_20 ;
V_20 = F_14 ( V_2 , V_2 -> V_37 ) ;
if ( V_20 ) {
F_19 ( L_3 ) ;
goto V_30;
}
V_20 = F_20 ( sizeof( struct V_19 ) , V_38 ) ;
if ( ! V_20 ) {
F_15 ( V_28 L_1
L_4 ,
V_29 , __LINE__ ) ;
V_36 = - V_39 ;
goto V_40;
}
V_35 = F_21 ( V_2 , V_33 ) ;
if ( ! V_35 ) {
F_15 ( V_28 L_1
L_4 ,
V_29 , __LINE__ ) ;
V_36 = - V_39 ;
goto V_40;
}
F_19 ( L_5 ) ;
V_20 -> V_22 = V_35 ;
V_20 -> V_24 = V_2 ;
F_22 ( & V_20 -> V_21 ) ;
F_4 ( & V_41 , V_9 ) ;
V_31 [ V_2 -> V_37 ] = V_20 ;
F_17 ( & V_20 -> V_21 ) ;
F_23 ( V_23 ) ;
F_24 ( V_2 -> V_32 , & V_20 -> V_21 ,
F_9 ) ;
F_5 ( & V_41 , V_9 ) ;
goto V_30;
V_40:
F_12 ( V_20 ) ;
V_30:
return V_36 ;
}
static int F_25 ( int V_42 )
{
int V_43 , V_44 ;
if ( V_42 == V_45 ) {
V_44 = V_11 ;
V_43 = 0 ;
} else {
if ( V_42 >= V_11 ) {
F_15 ( V_28 L_1
L_6
L_7 ,
V_29 , __LINE__ , V_42 ) ;
goto V_30;
}
V_44 = V_42 + 1 ;
V_43 = V_42 ;
}
for (; V_43 < V_44 ; V_43 ++ ) {
if ( V_31 [ V_43 ] ) {
F_26 ( & V_31 [ V_43 ] -> V_21 ,
F_9 ) ;
V_31 [ V_43 ] = NULL ;
}
}
V_30:
return 0 ;
}
static inline unsigned long F_27 ( struct V_46 * V_46 )
{
unsigned long V_47 ;
if ( V_46 -> V_48 -> V_49 & V_50 )
return ( unsigned long ) V_46 -> V_48 ;
F_28 ( V_46 , & V_47 ) ;
return V_47 ;
}
static unsigned long
F_29 ( struct V_2 * V_2 , unsigned int * V_51 ,
unsigned long * V_52 ,
unsigned long V_53 )
{
unsigned long V_54 = 0 ;
unsigned int V_55 = 0 ;
struct V_56 * V_57 = NULL ;
struct V_58 * V_59 ;
struct V_60 * V_61 = V_2 -> V_61 ;
if ( ! V_61 )
goto V_30;
F_30 ( & V_61 -> V_62 ) ;
for ( V_59 = V_61 -> V_63 ; V_59 ; V_59 = V_59 -> V_64 ) {
if ( ! V_59 -> V_65 )
continue;
if ( ! ( V_59 -> V_66 & V_67 ) )
continue;
V_54 = F_27 ( & V_59 -> V_65 -> V_68 ) ;
F_19 ( L_8 ,
V_59 -> V_65 -> V_69 -> V_70 . V_71 ) ;
V_57 = V_59 -> V_65 ;
break;
}
for ( V_59 = V_61 -> V_63 ; V_59 ; V_59 = V_59 -> V_64 ) {
if ( V_59 -> V_72 > V_53 || V_59 -> V_73 <= V_53 )
continue;
V_55 = V_53 - V_59 -> V_72 ;
if ( ! V_59 -> V_65 )
goto V_74;
F_19 ( L_9 ,
V_55 , V_53 ,
V_59 -> V_65 -> V_69 -> V_70 . V_71 ) ;
* V_51 = V_55 ;
break;
}
* V_52 = F_27 ( & V_59 -> V_65 -> V_68 ) ;
F_19 ( L_8 , V_59 -> V_65 -> V_69 -> V_70 . V_71 ) ;
F_31 ( & V_61 -> V_62 ) ;
V_30:
return V_54 ;
V_74:
F_31 ( & V_61 -> V_62 ) ;
F_15 ( V_28 L_1
L_10 ,
V_29 , __LINE__ ) ;
goto V_30;
}
static int F_32 ( struct V_2 * V_2 , unsigned long V_33 )
{
unsigned long V_9 ;
int V_36 ;
unsigned int V_75 = 0 ;
unsigned long V_76 = 0 , V_77 ;
V_36 = F_18 ( V_2 , V_33 ) ;
if ( V_36 )
goto V_30;
V_77 = F_29 ( V_2 , & V_75 , & V_76 , V_33 ) ;
if ( ! V_77 || ! V_76 ) {
V_36 = - V_78 ;
goto V_30;
}
F_4 ( & V_12 , V_9 ) ;
F_1 ( V_79 , V_2 -> V_37 ) ;
F_1 ( V_80 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_37 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_81 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_82 , V_2 -> V_37 ) ;
F_1 ( V_77 , V_2 -> V_37 ) ;
F_1 ( V_76 , V_2 -> V_37 ) ;
F_1 ( V_75 , V_2 -> V_37 ) ;
V_4 [ V_2 -> V_37 ] . V_83 = 1 ;
F_5 ( & V_12 , V_9 ) ;
F_33 () ;
V_30:
return V_36 ;
}
static int F_34 ( struct V_84 * V_85 , unsigned long V_86 ,
void * V_87 )
{
int V_36 ;
unsigned long V_9 ;
struct V_2 * V_24 = V_87 ;
F_19 ( L_11 ) ;
if ( ! V_86 ) {
F_4 ( & V_41 , V_9 ) ;
V_36 = F_25 ( V_24 -> V_37 ) ;
F_5 ( & V_41 , V_9 ) ;
} else {
V_36 = F_32 ( V_24 , V_86 ) ;
}
return V_36 ;
}
static int F_35 ( void )
{
T_1 V_88 ; T_1 V_89 ;
int V_90 = 0 ;
F_36 (cpu) {
V_89 = F_37 ( V_88 ) + 1 ;
if ( V_89 > V_90 )
V_90 ++ ;
}
return V_90 ;
}
static int F_38 ( void )
{
int V_2 ;
V_7 = F_39 () ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
V_4 [ V_2 ] . V_5 = 0 ;
V_4 [ V_2 ] . V_6 = 0 ;
V_4 [ V_2 ] . V_8 = F_20 ( ( V_7
* sizeof( unsigned long ) ) ,
V_38 ) ;
if ( ! V_4 [ V_2 ] . V_8 ) {
F_15 ( V_28 L_1
L_12
L_13 ,
V_29 , __LINE__ , V_2 ) ;
while ( V_2 >= 0 ) {
F_12 ( V_4 [ V_2 ] . V_8 ) ;
V_4 [ V_2 ] . V_8 = 0 ;
V_2 -- ;
}
return - V_39 ;
}
}
return 0 ;
}
int F_40 ( void )
{
int V_2 ;
int V_91 = V_92 ;
int V_93 ;
unsigned long V_9 = 0 ;
V_94 = F_35 () ;
V_11 = V_94 * 8 ;
F_41 ( & V_16 , F_7 ) ;
V_91 = F_38 () ;
if ( V_91 )
goto V_30;
F_4 ( & V_12 , V_9 ) ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
F_1 ( V_79 , V_2 ) ;
F_1 ( V_95 , V_2 ) ;
F_1 ( V_11 , V_2 ) ;
}
F_5 ( & V_12 , V_9 ) ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
V_4 [ V_2 ] . V_83 = 0 ;
V_4 [ V_2 ] . V_96 = 0 ;
}
V_93 = F_42 ( & V_97 ) ;
if ( V_93 ) {
V_91 = V_98 ;
goto V_30;
}
F_19 ( L_14 ) ;
V_30:
return V_91 ;
}
void F_43 ( int V_25 , unsigned int * V_99 ,
int V_100 )
{
unsigned long long V_101 ;
unsigned long V_9 ;
int V_102 ;
struct V_34 * V_22 ;
struct V_2 * V_24 ;
unsigned long long V_103 = V_25 ;
unsigned long long V_104 = V_103 << 32 ;
struct V_19 * V_105 ;
F_4 ( & V_41 , V_9 ) ;
V_105 = F_14 ( NULL , V_25 ) ;
if ( ! V_105 ) {
F_19 ( L_15
L_16 , V_25 ) ;
goto V_30;
}
V_22 = V_105 -> V_22 ;
V_24 = V_105 -> V_24 ;
F_44 ( & V_12 ) ;
for ( V_102 = 0 ; V_102 < V_100 ; V_102 ++ ) {
unsigned int V_106 = * ( V_99 + V_102 ) ;
int V_107 = 0 ;
V_101 = 0 ;
if ( V_106 == 0 )
continue;
V_101 = F_45 ( V_22 , V_106 , V_24 , & V_107 ) ;
if ( V_107 && V_107 != V_4 [ V_25 ] . V_96 ) {
V_4 [ V_25 ] . V_96 = V_107 ;
break;
}
if ( V_4 [ V_25 ] . V_83 )
F_1 ( ( V_101 | V_104 ) ,
V_25 ) ;
}
F_46 ( & V_12 ) ;
V_30:
F_5 ( & V_41 , V_9 ) ;
}
int F_47 ( void )
{
unsigned long V_9 = 0 ;
int V_91 ;
int V_108 ;
V_91 = F_48 ( & V_97 ) ;
if ( V_91 )
F_15 ( V_28 L_1
L_17 \
L_18 ,
V_29 , __LINE__ , V_91 ) ;
F_3 () ;
F_4 ( & V_41 , V_9 ) ;
V_91 = F_25 ( V_45 ) ;
F_5 ( & V_41 , V_9 ) ;
F_49 ( & V_16 ) ;
for ( V_108 = 0 ; V_108 < V_11 ; V_108 ++ ) {
V_4 [ V_108 ] . V_83 = 0 ;
F_12 ( V_4 [ V_108 ] . V_8 ) ;
V_4 [ V_108 ] . V_8 = 0 ;
}
F_19 ( L_19 ) ;
return V_91 ;
}
