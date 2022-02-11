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
struct V_56 * V_57 ;
struct V_58 * V_59 = V_2 -> V_59 ;
if ( ! V_59 )
goto V_30;
F_30 ( & V_59 -> V_60 ) ;
if ( V_59 -> V_61 ) {
V_54 = F_27 ( & V_59 -> V_61 -> V_62 ) ;
F_19 ( L_8 , V_59 -> V_61 ) ;
}
for ( V_57 = V_59 -> V_63 ; V_57 ; V_57 = V_57 -> V_64 ) {
if ( V_57 -> V_65 > V_53 || V_57 -> V_66 <= V_53 )
continue;
V_55 = V_53 - V_57 -> V_65 ;
if ( ! V_57 -> V_67 )
goto V_68;
F_19 ( L_9 ,
V_55 , V_53 , V_57 -> V_67 ) ;
* V_51 = V_55 ;
break;
}
* V_52 = F_27 ( & V_57 -> V_67 -> V_62 ) ;
F_19 ( L_8 , V_57 -> V_67 ) ;
F_31 ( & V_59 -> V_60 ) ;
V_30:
return V_54 ;
V_68:
F_31 ( & V_59 -> V_60 ) ;
F_15 ( V_28 L_1
L_10 ,
V_29 , __LINE__ ) ;
goto V_30;
}
static int F_32 ( struct V_2 * V_2 , unsigned long V_33 )
{
unsigned long V_9 ;
int V_36 ;
unsigned int V_69 = 0 ;
unsigned long V_70 = 0 , V_71 ;
V_36 = F_18 ( V_2 , V_33 ) ;
if ( V_36 )
goto V_30;
V_71 = F_29 ( V_2 , & V_69 , & V_70 , V_33 ) ;
if ( ! V_71 || ! V_70 ) {
V_36 = - V_72 ;
goto V_30;
}
F_4 ( & V_12 , V_9 ) ;
F_1 ( V_73 , V_2 -> V_37 ) ;
F_1 ( V_74 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_37 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_75 , V_2 -> V_37 ) ;
F_1 ( V_2 -> V_76 , V_2 -> V_37 ) ;
F_1 ( V_71 , V_2 -> V_37 ) ;
F_1 ( V_70 , V_2 -> V_37 ) ;
F_1 ( V_69 , V_2 -> V_37 ) ;
V_4 [ V_2 -> V_37 ] . V_77 = 1 ;
F_5 ( & V_12 , V_9 ) ;
F_33 () ;
V_30:
return V_36 ;
}
static int F_34 ( struct V_78 * V_79 , unsigned long V_80 ,
void * V_81 )
{
int V_36 ;
unsigned long V_9 ;
struct V_2 * V_24 = V_81 ;
F_19 ( L_11 ) ;
if ( ! V_80 ) {
F_4 ( & V_41 , V_9 ) ;
V_36 = F_25 ( V_24 -> V_37 ) ;
F_5 ( & V_41 , V_9 ) ;
} else {
V_36 = F_32 ( V_24 , V_80 ) ;
}
return V_36 ;
}
static int F_35 ( void )
{
T_1 V_82 ; T_1 V_83 ;
int V_84 = 0 ;
F_36 (cpu) {
V_83 = F_37 ( V_82 ) + 1 ;
if ( V_83 > V_84 )
V_84 ++ ;
}
return V_84 ;
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
int V_85 = V_86 ;
int V_87 ;
unsigned long V_9 = 0 ;
V_88 = F_35 () ;
V_11 = V_88 * 8 ;
F_41 ( & V_16 , F_7 ) ;
V_85 = F_38 () ;
if ( V_85 )
goto V_30;
F_4 ( & V_12 , V_9 ) ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
F_1 ( V_73 , V_2 ) ;
F_1 ( V_89 , V_2 ) ;
F_1 ( V_11 , V_2 ) ;
}
F_5 ( & V_12 , V_9 ) ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 ++ ) {
V_4 [ V_2 ] . V_77 = 0 ;
V_4 [ V_2 ] . V_90 = 0 ;
}
V_87 = F_42 ( & V_91 ) ;
if ( V_87 ) {
V_85 = V_92 ;
goto V_30;
}
F_19 ( L_14 ) ;
V_30:
return V_85 ;
}
void F_43 ( int V_25 , unsigned int * V_93 ,
int V_94 )
{
unsigned long long V_95 ;
unsigned long V_9 ;
int V_96 ;
struct V_34 * V_22 ;
struct V_2 * V_24 ;
unsigned long long V_97 = V_25 ;
unsigned long long V_98 = V_97 << 32 ;
struct V_19 * V_99 ;
F_4 ( & V_41 , V_9 ) ;
V_99 = F_14 ( NULL , V_25 ) ;
if ( ! V_99 ) {
F_19 ( L_15
L_16 , V_25 ) ;
goto V_30;
}
V_22 = V_99 -> V_22 ;
V_24 = V_99 -> V_24 ;
F_44 ( & V_12 ) ;
for ( V_96 = 0 ; V_96 < V_94 ; V_96 ++ ) {
unsigned int V_100 = * ( V_93 + V_96 ) ;
int V_101 = 0 ;
V_95 = 0 ;
if ( V_100 == 0 )
continue;
V_95 = F_45 ( V_22 , V_100 , V_24 , & V_101 ) ;
if ( V_101 && V_101 != V_4 [ V_25 ] . V_90 ) {
V_4 [ V_25 ] . V_90 = V_101 ;
break;
}
if ( V_4 [ V_25 ] . V_77 )
F_1 ( ( V_95 | V_98 ) ,
V_25 ) ;
}
F_46 ( & V_12 ) ;
V_30:
F_5 ( & V_41 , V_9 ) ;
}
int F_47 ( void )
{
unsigned long V_9 = 0 ;
int V_85 ;
int V_102 ;
V_85 = F_48 ( & V_91 ) ;
if ( V_85 )
F_15 ( V_28 L_1
L_17 \
L_18 ,
V_29 , __LINE__ , V_85 ) ;
F_3 () ;
F_4 ( & V_41 , V_9 ) ;
V_85 = F_25 ( V_45 ) ;
F_5 ( & V_41 , V_9 ) ;
F_49 ( & V_16 ) ;
for ( V_102 = 0 ; V_102 < V_11 ; V_102 ++ ) {
V_4 [ V_102 ] . V_77 = 0 ;
F_12 ( V_4 [ V_102 ] . V_8 ) ;
V_4 [ V_102 ] . V_8 = 0 ;
}
F_19 ( L_19 ) ;
return V_85 ;
}
