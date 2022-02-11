static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_7 ;
struct V_8 * V_9 = V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
int V_20 ;
const char * V_21 ;
if ( V_22 -> V_23 & V_24 )
return;
if ( F_2 ( ! V_9 ) )
return;
F_3 ( V_19 ) ;
V_22 -> V_23 |= V_24 ;
V_12 = F_4 ( V_9 -> V_25 . V_12 ) ;
if ( F_5 ( & V_12 -> V_26 ) )
goto V_27;
V_20 = F_6 () ;
V_18 = V_9 -> V_25 . V_18 ;
V_14 = F_7 ( V_18 , V_28 ,
sizeof( * V_16 ) , V_19 , V_20 ) ;
if ( ! V_14 )
goto V_27;
V_16 = F_8 ( V_14 ) ;
V_21 = V_2 -> V_12 . V_29 + strlen ( V_2 -> V_12 . V_29 ) ;
while ( V_21 >= V_2 -> V_12 . V_29 && * V_21 != '/' )
V_21 -- ;
V_21 ++ ;
strncpy ( V_16 -> V_30 , V_2 -> V_12 . V_30 , V_31 ) ;
strncpy ( V_16 -> V_29 , V_21 , V_32 ) ;
V_16 -> V_30 [ V_31 ] = 0 ;
V_16 -> V_29 [ V_32 ] = 0 ;
V_16 -> V_33 = V_2 -> V_33 ;
V_16 -> line = V_2 -> V_12 . line ;
V_16 -> V_34 = V_3 == V_4 ;
if ( ! F_9 ( V_6 , V_16 , V_18 , V_14 ) )
F_10 ( V_18 , V_14 ) ;
V_27:
V_22 -> V_23 &= ~ V_24 ;
F_11 ( V_19 ) ;
}
static inline
void F_12 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( ! V_35 )
return;
F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_36 ) ;
V_10 = V_9 ;
F_15 () ;
V_35 ++ ;
F_16 ( & V_36 ) ;
return 0 ;
}
void F_17 ( void )
{
F_14 ( & V_36 ) ;
if ( ! V_35 )
goto V_37;
V_35 -- ;
V_37:
F_16 ( & V_36 ) ;
}
static int F_18 ( struct V_8 * V_9 )
{
return F_13 ( V_9 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
F_17 () ;
}
static enum V_38 F_20 ( struct V_39 * V_40 ,
int V_19 , struct V_41 * V_14 )
{
struct V_15 * V_42 ;
F_21 ( V_42 , V_40 -> V_43 ) ;
F_22 ( & V_40 -> V_44 , L_1 ,
V_42 -> V_34 ? L_2 : L_3 ,
V_42 -> V_30 ,
V_42 -> V_29 ,
V_42 -> line ) ;
return F_23 ( & V_40 -> V_44 ) ;
}
static void F_24 ( struct V_45 * V_46 )
{
F_25 ( V_46 , L_4
L_5
L_6
L_7 ) ;
}
T_1 static int F_26 ( void )
{
int V_47 ;
V_47 = F_27 ( & V_48 ) ;
if ( ! V_47 ) {
F_28 ( V_49 L_8
L_9 ) ;
return 1 ;
}
return F_29 ( & V_50 ) ;
}
static inline
void F_12 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
}
void F_30 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_51 )
{
if ( V_51 ) {
V_2 -> V_33 ++ ;
V_3 = V_4 ;
}
F_12 ( V_2 , V_3 , V_4 ) ;
if ( V_3 == V_4 )
V_2 -> V_12 . V_34 ++ ;
else
V_2 -> V_12 . V_52 ++ ;
}
static int F_31 ( struct V_45 * V_53 )
{
F_25 ( V_53 , L_10
L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static inline long F_32 ( struct V_54 * V_21 )
{
long V_55 ;
if ( V_21 -> V_34 ) {
V_55 = V_21 -> V_52 * 100 ;
V_55 /= V_21 -> V_34 + V_21 -> V_52 ;
} else
V_55 = V_21 -> V_52 ? 100 : - 1 ;
return V_55 ;
}
static const char * F_33 ( struct V_54 * V_21 )
{
const char * V_2 ;
V_2 = V_21 -> V_29 + strlen ( V_21 -> V_29 ) ;
while ( V_2 >= V_21 -> V_29 && * V_2 != '/' )
V_2 -- ;
return ++ V_2 ;
}
static void F_34 ( struct V_45 * V_53 ,
struct V_54 * V_21 , const char * V_2 )
{
long V_55 ;
V_55 = F_32 ( V_21 ) ;
if ( V_55 < 0 )
F_25 ( V_53 , L_16 ) ;
else
F_35 ( V_53 , L_17 , V_55 ) ;
F_35 ( V_53 , L_18 , V_21 -> V_30 , V_2 , V_21 -> line ) ;
}
static int F_36 ( struct V_45 * V_53 ,
struct V_54 * V_21 , const char * V_2 )
{
F_35 ( V_53 , L_19 , V_21 -> V_34 , V_21 -> V_52 ) ;
F_34 ( V_53 , V_21 , V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_45 * V_53 , void * V_56 )
{
struct V_1 * V_21 = V_56 ;
const char * V_2 ;
int V_57 ;
V_2 = F_33 ( & V_21 -> V_12 ) ;
if ( ! V_21 -> V_33 )
return F_36 ( V_53 , & V_21 -> V_12 , V_2 ) ;
V_57 = snprintf ( NULL , 0 , L_20 , V_21 -> V_33 ) ;
V_57 = V_57 > 8 ? 0 : 8 - V_57 ;
F_35 ( V_53 , L_21 ,
V_21 -> V_12 . V_34 , V_21 -> V_33 , V_57 , V_21 -> V_12 . V_52 ) ;
F_34 ( V_53 , & V_21 -> V_12 , V_2 ) ;
return 0 ;
}
static void * F_38 ( struct V_58 * V_59 )
{
return V_60 ;
}
static void *
F_39 ( void * V_56 , int V_61 )
{
struct V_1 * V_21 = V_56 ;
++ V_21 ;
if ( ( void * ) V_21 >= ( void * ) V_62 )
return NULL ;
return V_21 ;
}
static int F_40 ( void * V_63 , void * V_64 )
{
struct V_54 * V_65 = V_63 ;
struct V_54 * V_66 = V_64 ;
long V_67 , V_68 ;
V_67 = F_32 ( V_65 ) ;
V_68 = F_32 ( V_66 ) ;
if ( V_67 < V_68 )
return - 1 ;
if ( V_67 > V_68 )
return 1 ;
if ( V_65 -> V_52 < V_66 -> V_52 )
return - 1 ;
if ( V_65 -> V_52 > V_66 -> V_52 )
return 1 ;
if ( V_65 -> V_34 > V_66 -> V_34 )
return - 1 ;
if ( V_65 -> V_34 < V_66 -> V_34 )
return 1 ;
return 0 ;
}
T_1 static int F_41 ( void )
{
int V_47 ;
V_47 = F_42 ( & V_69 ) ;
if ( ! V_47 ) {
F_28 ( V_49 L_8
L_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_45 * V_53 )
{
F_25 ( V_53 , L_23
L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static void * F_44 ( struct V_58 * V_59 )
{
return V_70 ;
}
static void *
F_45 ( void * V_56 , int V_61 )
{
struct V_54 * V_21 = V_56 ;
++ V_21 ;
if ( ( void * ) V_21 >= ( void * ) V_71 )
return NULL ;
return V_21 ;
}
static int F_46 ( struct V_45 * V_53 , void * V_56 )
{
struct V_54 * V_21 = V_56 ;
const char * V_2 ;
V_2 = F_33 ( V_21 ) ;
return F_36 ( V_53 , V_21 , V_2 ) ;
}
T_1 static int F_47 ( void )
{
int V_47 ;
V_47 = F_42 ( & V_72 ) ;
if ( ! V_47 ) {
F_28 ( V_49 L_8
L_24 ) ;
return 1 ;
}
return 0 ;
}
