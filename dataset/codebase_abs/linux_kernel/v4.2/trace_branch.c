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
V_21 = V_2 -> V_29 + strlen ( V_2 -> V_29 ) ;
while ( V_21 >= V_2 -> V_29 && * V_21 != '/' )
V_21 -- ;
V_21 ++ ;
strncpy ( V_16 -> V_30 , V_2 -> V_30 , V_31 ) ;
strncpy ( V_16 -> V_29 , V_21 , V_32 ) ;
V_16 -> V_30 [ V_31 ] = 0 ;
V_16 -> V_29 [ V_32 ] = 0 ;
V_16 -> line = V_2 -> line ;
V_16 -> V_33 = V_3 == V_4 ;
if ( ! F_9 ( V_6 , V_16 , V_18 , V_14 ) )
F_10 ( V_18 , V_14 ) ;
V_27:
V_22 -> V_23 &= ~ V_24 ;
F_11 ( V_19 ) ;
}
static inline
void F_12 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
if ( ! V_34 )
return;
F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_13 ( struct V_8 * V_9 )
{
F_14 ( & V_35 ) ;
V_10 = V_9 ;
F_15 () ;
V_34 ++ ;
F_16 ( & V_35 ) ;
return 0 ;
}
void F_17 ( void )
{
F_14 ( & V_35 ) ;
if ( ! V_34 )
goto V_36;
V_34 -- ;
V_36:
F_16 ( & V_35 ) ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_13 ( V_9 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
F_17 () ;
}
static int F_20 ( struct V_8 * V_9 )
{
F_18 ( V_9 ) ;
return 0 ;
}
static void F_21 ( struct V_8 * V_9 )
{
F_19 ( V_9 ) ;
}
static enum V_37 F_22 ( struct V_38 * V_39 ,
int V_19 , struct V_40 * V_14 )
{
struct V_15 * V_41 ;
F_23 ( V_41 , V_39 -> V_42 ) ;
F_24 ( & V_39 -> V_43 , L_1 ,
V_41 -> V_33 ? L_2 : L_3 ,
V_41 -> V_30 ,
V_41 -> V_29 ,
V_41 -> line ) ;
return F_25 ( & V_39 -> V_43 ) ;
}
static void F_26 ( struct V_44 * V_45 )
{
F_27 ( V_45 , L_4
L_5
L_6
L_7 ) ;
}
T_1 static int F_28 ( void )
{
int V_46 ;
V_46 = F_29 ( & V_47 ) ;
if ( ! V_46 ) {
F_30 ( V_48 L_8
L_9 ) ;
return 1 ;
}
return F_31 ( & V_49 ) ;
}
static inline
void F_12 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
}
void F_32 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_12 ( V_2 , V_3 , V_4 ) ;
if ( V_3 == V_4 )
V_2 -> V_33 ++ ;
else
V_2 -> V_50 ++ ;
}
static int F_33 ( struct V_44 * V_51 )
{
F_27 ( V_51 , L_10
L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static inline long F_34 ( struct V_1 * V_21 )
{
long V_52 ;
if ( V_21 -> V_33 ) {
V_52 = V_21 -> V_50 * 100 ;
V_52 /= V_21 -> V_33 + V_21 -> V_50 ;
} else
V_52 = V_21 -> V_50 ? 100 : - 1 ;
return V_52 ;
}
static int F_35 ( struct V_44 * V_51 , void * V_53 )
{
struct V_1 * V_21 = V_53 ;
const char * V_2 ;
long V_52 ;
V_2 = V_21 -> V_29 + strlen ( V_21 -> V_29 ) ;
while ( V_2 >= V_21 -> V_29 && * V_2 != '/' )
V_2 -- ;
V_2 ++ ;
V_52 = F_34 ( V_21 ) ;
F_36 ( V_51 , L_16 , V_21 -> V_33 , V_21 -> V_50 ) ;
if ( V_52 < 0 )
F_27 ( V_51 , L_17 ) ;
else
F_36 ( V_51 , L_18 , V_52 ) ;
F_36 ( V_51 , L_19 , V_21 -> V_30 , V_2 , V_21 -> line ) ;
return 0 ;
}
static void * F_37 ( struct V_54 * V_55 )
{
return V_56 ;
}
static void *
F_38 ( void * V_53 , int V_57 )
{
struct V_1 * V_21 = V_53 ;
++ V_21 ;
if ( ( void * ) V_21 >= ( void * ) V_58 )
return NULL ;
return V_21 ;
}
static int F_39 ( void * V_59 , void * V_60 )
{
struct V_1 * V_61 = V_59 ;
struct V_1 * V_62 = V_60 ;
long V_63 , V_64 ;
V_63 = F_34 ( V_61 ) ;
V_64 = F_34 ( V_62 ) ;
if ( V_63 < V_64 )
return - 1 ;
if ( V_63 > V_64 )
return 1 ;
if ( V_61 -> V_50 < V_62 -> V_50 )
return - 1 ;
if ( V_61 -> V_50 > V_62 -> V_50 )
return 1 ;
if ( V_61 -> V_33 > V_62 -> V_33 )
return - 1 ;
if ( V_61 -> V_33 < V_62 -> V_33 )
return 1 ;
return 0 ;
}
T_1 static int F_40 ( void )
{
int V_46 ;
V_46 = F_41 ( & V_65 ) ;
if ( ! V_46 ) {
F_30 ( V_48 L_8
L_20 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_44 * V_51 )
{
F_27 ( V_51 , L_21
L_11
L_12
L_13
L_14
L_15 ) ;
return 0 ;
}
static void * F_43 ( struct V_54 * V_55 )
{
return V_66 ;
}
static void *
F_44 ( void * V_53 , int V_57 )
{
struct V_1 * V_21 = V_53 ;
++ V_21 ;
if ( ( void * ) V_21 >= ( void * ) V_67 )
return NULL ;
return V_21 ;
}
T_1 static int F_45 ( void )
{
int V_46 ;
V_46 = F_41 ( & V_68 ) ;
if ( ! V_46 ) {
F_30 ( V_48 L_8
L_22 ) ;
return 1 ;
}
return 0 ;
}
