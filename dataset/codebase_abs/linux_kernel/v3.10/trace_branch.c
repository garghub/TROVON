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
int V_20 , V_21 ;
const char * V_22 ;
if ( F_2 ( ! V_9 ) )
return;
F_3 ( V_19 ) ;
V_20 = F_4 () ;
V_12 = F_5 ( V_9 -> V_23 . V_12 , V_20 ) ;
if ( F_6 ( & V_12 -> V_24 ) != 1 )
goto V_25;
V_21 = F_7 () ;
V_18 = V_9 -> V_23 . V_18 ;
V_14 = F_8 ( V_18 , V_26 ,
sizeof( * V_16 ) , V_19 , V_21 ) ;
if ( ! V_14 )
goto V_25;
V_16 = F_9 ( V_14 ) ;
V_22 = V_2 -> V_27 + strlen ( V_2 -> V_27 ) ;
while ( V_22 >= V_2 -> V_27 && * V_22 != '/' )
V_22 -- ;
V_22 ++ ;
strncpy ( V_16 -> V_28 , V_2 -> V_28 , V_29 ) ;
strncpy ( V_16 -> V_27 , V_22 , V_30 ) ;
V_16 -> V_28 [ V_29 ] = 0 ;
V_16 -> V_27 [ V_30 ] = 0 ;
V_16 -> line = V_2 -> line ;
V_16 -> V_31 = V_3 == V_4 ;
if ( ! F_10 ( V_6 , V_16 , V_18 , V_14 ) )
F_11 ( V_18 , V_14 ) ;
V_25:
F_12 ( & V_12 -> V_24 ) ;
F_13 ( V_19 ) ;
}
static inline
void F_14 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( ! V_32 )
return;
F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_15 ( struct V_8 * V_9 )
{
F_16 ( & V_33 ) ;
V_10 = V_9 ;
F_17 () ;
V_32 ++ ;
F_18 ( & V_33 ) ;
return 0 ;
}
void F_19 ( void )
{
F_16 ( & V_33 ) ;
if ( ! V_32 )
goto V_34;
V_32 -- ;
V_34:
F_18 ( & V_33 ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
F_15 ( V_9 ) ;
}
static void F_21 ( struct V_8 * V_9 )
{
F_19 () ;
}
static int F_22 ( struct V_8 * V_9 )
{
F_20 ( V_9 ) ;
return 0 ;
}
static void F_23 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
}
static enum V_35 F_24 ( struct V_36 * V_37 ,
int V_19 , struct V_38 * V_14 )
{
struct V_15 * V_39 ;
F_25 ( V_39 , V_37 -> V_40 ) ;
if ( F_26 ( & V_37 -> V_41 , L_1 ,
V_39 -> V_31 ? L_2 : L_3 ,
V_39 -> V_28 ,
V_39 -> V_27 ,
V_39 -> line ) )
return V_42 ;
return V_43 ;
}
static void F_27 ( struct V_44 * V_45 )
{
F_28 ( V_45 , L_4
L_5 ) ;
F_28 ( V_45 , L_6
L_7 ) ;
}
T_1 static int F_29 ( void )
{
int V_46 ;
V_46 = F_30 ( & V_47 ) ;
if ( ! V_46 ) {
F_31 ( V_48 L_8
L_9 ) ;
return 1 ;
}
return F_32 ( & V_49 ) ;
}
static inline
void F_14 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
}
void F_33 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_14 ( V_2 , V_3 , V_4 ) ;
if ( V_3 == V_4 )
V_2 -> V_31 ++ ;
else
V_2 -> V_50 ++ ;
}
static int F_34 ( struct V_44 * V_51 )
{
F_35 ( V_51 , L_10 ) ;
F_35 ( V_51 , L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static inline long F_36 ( struct V_1 * V_22 )
{
long V_52 ;
if ( V_22 -> V_31 ) {
V_52 = V_22 -> V_50 * 100 ;
V_52 /= V_22 -> V_31 + V_22 -> V_50 ;
} else
V_52 = V_22 -> V_50 ? 100 : - 1 ;
return V_52 ;
}
static int F_37 ( struct V_44 * V_51 , void * V_53 )
{
struct V_1 * V_22 = V_53 ;
const char * V_2 ;
long V_52 ;
V_2 = V_22 -> V_27 + strlen ( V_22 -> V_27 ) ;
while ( V_2 >= V_22 -> V_27 && * V_2 != '/' )
V_2 -- ;
V_2 ++ ;
V_52 = F_36 ( V_22 ) ;
F_35 ( V_51 , L_16 , V_22 -> V_31 , V_22 -> V_50 ) ;
if ( V_52 < 0 )
F_35 ( V_51 , L_17 ) ;
else
F_35 ( V_51 , L_18 , V_52 ) ;
F_35 ( V_51 , L_19 , V_22 -> V_28 , V_2 , V_22 -> line ) ;
return 0 ;
}
static void * F_38 ( struct V_54 * V_55 )
{
return V_56 ;
}
static void *
F_39 ( void * V_53 , int V_57 )
{
struct V_1 * V_22 = V_53 ;
++ V_22 ;
if ( ( void * ) V_22 >= ( void * ) V_58 )
return NULL ;
return V_22 ;
}
static int F_40 ( void * V_59 , void * V_60 )
{
struct V_1 * V_61 = V_59 ;
struct V_1 * V_62 = V_60 ;
long V_63 , V_64 ;
V_63 = F_36 ( V_61 ) ;
V_64 = F_36 ( V_62 ) ;
if ( V_63 < V_64 )
return - 1 ;
if ( V_63 > V_64 )
return 1 ;
if ( V_61 -> V_50 < V_62 -> V_50 )
return - 1 ;
if ( V_61 -> V_50 > V_62 -> V_50 )
return 1 ;
if ( V_61 -> V_31 > V_62 -> V_31 )
return - 1 ;
if ( V_61 -> V_31 < V_62 -> V_31 )
return 1 ;
return 0 ;
}
T_1 static int F_41 ( void )
{
int V_46 ;
V_46 = F_42 ( & V_65 ) ;
if ( ! V_46 ) {
F_31 ( V_48 L_8
L_20 ) ;
return 1 ;
}
return 0 ;
}
static int F_43 ( struct V_44 * V_51 )
{
F_35 ( V_51 , L_21 ) ;
F_35 ( V_51 , L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static void * F_44 ( struct V_54 * V_55 )
{
return V_66 ;
}
static void *
F_45 ( void * V_53 , int V_57 )
{
struct V_1 * V_22 = V_53 ;
++ V_22 ;
if ( ( void * ) V_22 >= ( void * ) V_67 )
return NULL ;
return V_22 ;
}
T_1 static int F_46 ( void )
{
int V_46 ;
V_46 = F_42 ( & V_68 ) ;
if ( ! V_46 ) {
F_31 ( V_48 L_8
L_22 ) ;
return 1 ;
}
return 0 ;
}
