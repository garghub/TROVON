static void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_6 ;
F_2 () ;
if ( F_3 ( V_5 -> V_7 -> V_8 ) )
return;
F_4 () ;
if ( V_1 == F_3 ( V_5 -> V_7 -> V_9 ) )
F_5 ( V_3 ) ;
}
static inline T_1
F_6 ( struct V_4 * V_10 )
{
T_1 V_11 = V_10 -> V_7 -> V_12 ;
return V_11 ;
}
static inline void
F_7 ( struct V_4 * V_10 ,
T_1 V_13 )
{
V_10 -> V_7 -> V_12 = V_13 ;
}
static inline void
F_8 ( struct V_4 * V_10 ,
T_1 V_14 )
{
V_10 -> V_7 -> V_9 = V_14 ;
V_10 -> V_15 = V_14 ;
}
static inline T_1
F_9 ( const struct V_4 * V_10 )
{
return V_10 -> V_16 ;
}
static inline T_2
F_10 ( struct V_4 * V_10 )
{
return ( T_2 ) V_10 -> V_7 -> V_12 << 32 ;
}
static T_1 F_11 (
struct V_4 * V_10 ,
T_1 V_17 ,
const void * V_18 ,
T_1 V_19 )
{
void * V_7 = F_12 ( V_10 ) ;
T_1 V_20 = F_9 ( V_10 ) ;
memcpy ( V_7 + V_17 , V_18 , V_19 ) ;
V_17 += V_19 ;
if ( V_17 >= V_20 )
V_17 -= V_20 ;
return V_17 ;
}
void F_13 ( const struct V_4 * V_10 ,
struct V_21 * V_22 )
{
T_1 V_23 ;
T_1 V_24 ;
if ( V_10 -> V_7 ) {
F_14 ( V_10 ,
& V_24 ,
& V_23 ) ;
V_22 -> V_24 = V_24 ;
V_22 -> V_23 = V_23 ;
V_22 -> V_25 =
V_10 -> V_7 -> V_9 ;
V_22 -> V_26 =
V_10 -> V_7 -> V_12 ;
V_22 -> V_27 =
V_10 -> V_7 -> V_8 ;
}
}
int F_15 ( struct V_4 * V_10 ,
struct V_28 * V_29 , T_1 V_30 )
{
int V_31 ;
struct V_28 * * V_32 ;
F_16 ( ( sizeof( struct V_33 ) != V_34 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_4 ) ) ;
V_32 = F_17 ( sizeof( struct V_28 * ) * ( V_30 * 2 - 1 ) ,
V_35 ) ;
if ( ! V_32 )
return - V_36 ;
V_32 [ 0 ] = V_29 ;
for ( V_31 = 0 ; V_31 < 2 * ( V_30 - 1 ) ; V_31 ++ )
V_32 [ V_31 + 1 ] = & V_29 [ V_31 % ( V_30 - 1 ) + 1 ] ;
V_10 -> V_7 = (struct V_33 * )
F_18 ( V_32 , V_30 * 2 - 1 , V_37 , V_38 ) ;
F_19 ( V_32 ) ;
if ( ! V_10 -> V_7 )
return - V_36 ;
V_10 -> V_7 -> V_9 =
V_10 -> V_7 -> V_12 = 0 ;
V_10 -> V_7 -> V_39 . V_40 = 1 ;
V_10 -> V_41 = V_30 << V_42 ;
V_10 -> V_16 = V_10 -> V_41 -
sizeof( struct V_33 ) ;
F_20 ( & V_10 -> V_43 ) ;
return 0 ;
}
void F_21 ( struct V_4 * V_10 )
{
F_22 ( V_10 -> V_7 ) ;
}
int F_23 ( struct V_2 * V_3 ,
const struct V_44 * V_45 , T_1 V_46 )
{
int V_31 ;
T_1 V_23 ;
T_1 V_47 = sizeof( T_2 ) ;
T_1 V_13 ;
T_1 V_1 ;
T_2 V_48 ;
unsigned long V_49 ;
struct V_4 * V_50 = & V_3 -> V_6 ;
if ( V_3 -> V_51 )
return - V_52 ;
for ( V_31 = 0 ; V_31 < V_46 ; V_31 ++ )
V_47 += V_45 [ V_31 ] . V_53 ;
F_24 ( & V_50 -> V_43 , V_49 ) ;
V_23 = F_25 ( V_50 ) ;
if ( V_23 <= V_47 ) {
F_26 ( & V_50 -> V_43 , V_49 ) ;
return - V_54 ;
}
V_13 = F_6 ( V_50 ) ;
V_1 = V_13 ;
for ( V_31 = 0 ; V_31 < V_46 ; V_31 ++ ) {
V_13 = F_11 ( V_50 ,
V_13 ,
V_45 [ V_31 ] . V_55 ,
V_45 [ V_31 ] . V_53 ) ;
}
V_48 = F_10 ( V_50 ) ;
V_13 = F_11 ( V_50 ,
V_13 ,
& V_48 ,
sizeof( T_2 ) ) ;
F_2 () ;
F_7 ( V_50 , V_13 ) ;
F_26 ( & V_50 -> V_43 , V_49 ) ;
F_1 ( V_1 , V_3 ) ;
if ( V_3 -> V_51 )
return - V_52 ;
return 0 ;
}
int F_27 ( struct V_2 * V_3 ,
void * V_56 , T_1 V_57 , T_1 * V_58 ,
T_2 * V_59 , bool V_60 )
{
struct V_61 * V_62 ;
T_1 V_63 , V_64 ;
if ( F_28 ( V_57 == 0 ) )
return - V_65 ;
* V_58 = 0 ;
* V_59 = 0 ;
V_62 = F_29 ( V_3 ) ;
if ( V_62 == NULL ) {
return 0 ;
}
V_64 = V_60 ? 0 : ( V_62 -> V_66 << 3 ) ;
V_63 = ( V_62 -> V_67 << 3 ) - V_64 ;
* V_58 = V_63 ;
* V_59 = V_62 -> V_68 ;
if ( F_28 ( V_63 > V_57 ) )
return - V_69 ;
memcpy ( V_56 , ( const char * ) V_62 + V_64 , V_63 ) ;
F_30 ( V_3 , V_62 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static T_1 F_32 ( const struct V_4 * V_5 )
{
T_1 V_70 = V_5 -> V_15 ;
T_1 V_71 = F_3 ( V_5 -> V_7 -> V_12 ) ;
if ( V_71 >= V_70 )
return V_71 - V_70 ;
else
return ( V_5 -> V_16 - V_70 ) + V_71 ;
}
struct V_61 * F_29 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_72 ;
struct V_61 * V_62 ;
if ( F_32 ( V_5 ) < sizeof( struct V_61 ) )
return NULL ;
V_62 = F_12 ( V_5 ) + V_5 -> V_15 ;
if ( V_62 )
F_33 ( ( char * ) V_62 + ( V_62 -> V_67 << 3 ) ) ;
return V_62 ;
}
struct V_61 *
F_30 ( struct V_2 * V_3 ,
const struct V_61 * V_62 )
{
struct V_4 * V_5 = & V_3 -> V_72 ;
T_1 V_63 = V_62 -> V_67 << 3 ;
T_1 V_73 = V_5 -> V_16 ;
V_5 -> V_15 += V_63 + V_74 ;
if ( V_5 -> V_15 >= V_73 )
V_5 -> V_15 -= V_73 ;
return F_29 ( V_3 ) ;
}
void F_31 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_72 ;
T_1 V_75 = F_25 ( V_5 ) ;
F_4 () ;
V_5 -> V_7 -> V_9 = V_5 -> V_15 ;
F_2 () ;
if ( V_5 -> V_7 -> V_8 )
return;
if ( V_5 -> V_7 -> V_39 . V_76 ) {
T_1 V_77 = F_3 ( V_5 -> V_7 -> V_78 ) ;
if ( V_75 > V_77 )
return;
if ( F_25 ( V_5 ) < V_77 )
return;
}
F_5 ( V_3 ) ;
}
