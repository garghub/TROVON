static enum V_1
F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static T_1
F_2 ( struct V_2 * V_3 )
{
return F_3 ( V_3 ) -> V_5 . V_6 ;
}
static T_1
F_4 ( struct V_2 * V_3 )
{
return ( T_1 ) F_3 ( V_3 ) -> V_5 . V_7 << 12 ;
}
static void T_2 *
F_5 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_3 ( V_3 ) -> V_9 ;
unsigned long V_10 ;
F_6 ( & V_9 -> V_11 , V_10 ) ;
V_9 -> V_12 = V_10 ;
return NULL ;
}
static void
F_7 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_3 ( V_3 ) -> V_9 ;
F_8 ( & V_9 -> V_11 , V_9 -> V_12 ) ;
}
static T_3
F_9 ( struct V_2 * V_3 , T_1 V_6 )
{
struct F_3 * V_13 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_13 -> V_9 ;
struct V_14 * V_15 = V_9 -> V_16 . V_17 . V_15 ;
T_1 V_16 = ( V_13 -> V_5 . V_6 + V_6 ) & 0xffffff00000ULL ;
T_1 V_18 = ( V_13 -> V_5 . V_6 + V_6 ) & 0x000000fffffULL ;
T_3 V_19 ;
if ( F_10 ( V_9 -> V_18 != V_16 ) ) {
F_11 ( V_15 , 0x001700 , V_16 >> 16 ) ;
V_9 -> V_18 = V_16 ;
}
V_19 = F_12 ( V_15 , 0x700000 + V_18 ) ;
return V_19 ;
}
static void
F_13 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_19 )
{
struct F_3 * V_13 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_13 -> V_9 ;
struct V_14 * V_15 = V_9 -> V_16 . V_17 . V_15 ;
T_1 V_16 = ( V_13 -> V_5 . V_6 + V_6 ) & 0xffffff00000ULL ;
T_1 V_18 = ( V_13 -> V_5 . V_6 + V_6 ) & 0x000000fffffULL ;
if ( F_10 ( V_9 -> V_18 != V_16 ) ) {
F_11 ( V_15 , 0x001700 , V_16 >> 16 ) ;
V_9 -> V_18 = V_16 ;
}
F_11 ( V_15 , 0x700000 + V_18 , V_19 ) ;
}
static void
F_14 ( struct V_2 * V_3 , struct V_20 * V_21 , T_1 V_6 )
{
struct F_3 * V_13 = F_3 ( V_3 ) ;
F_15 ( V_21 , V_6 , & V_13 -> V_5 ) ;
}
static void
F_16 ( struct F_3 * V_22 )
{
struct V_23 * V_13 = ( void * ) V_22 ;
struct V_8 * V_9 = V_22 -> V_9 ;
struct V_15 * V_24 = V_9 -> V_16 . V_17 . V_15 -> V_24 ;
if ( F_10 ( ! V_13 -> V_25 ) )
return;
F_17 ( V_24 , V_22 -> V_5 . V_7 << V_26 , V_13 -> V_25 ,
V_13 -> V_27 , & V_9 -> V_28 ) ;
}
static void
F_18 ( struct F_3 * V_22 )
{
struct V_29 * V_13 = ( void * ) V_22 ;
struct V_8 * V_9 = V_22 -> V_9 ;
struct V_30 * V_31 ;
int V_32 ;
if ( F_10 ( F_19 ( & V_22 -> V_5 . V_33 ) ) )
return;
V_31 = F_20 ( & V_22 -> V_5 . V_33 , struct V_30 ,
V_34 ) ;
V_31 -> V_6 &= ~ F_21 ( 34 - V_9 -> V_35 ) ;
for ( V_32 = 0 ; V_32 < V_22 -> V_5 . V_7 ; V_32 ++ ) {
F_22 ( V_9 -> V_36 ,
( V_31 -> V_6 + V_32 ) << V_9 -> V_35 , V_37 ) ;
F_23 ( V_13 -> V_38 [ V_32 ] ) ;
}
F_24 ( V_9 -> V_39 ) ;
F_25 ( V_9 -> V_40 , & V_31 ) ;
F_26 ( V_9 -> V_39 ) ;
}
static void *
F_27 ( struct V_2 * V_3 )
{
struct F_3 * V_13 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_13 -> V_9 ;
if ( V_9 -> V_36 )
F_18 ( V_13 ) ;
else
F_16 ( V_13 ) ;
return V_13 ;
}
static int
F_28 ( struct V_8 * V_9 , T_3 V_41 , T_3 V_42 ,
struct F_3 * * V_22 )
{
struct V_23 * V_13 ;
struct V_43 * V_17 = & V_9 -> V_16 . V_17 ;
struct V_15 * V_24 = V_17 -> V_15 -> V_24 ;
if ( ! ( V_13 = F_29 ( sizeof( * V_13 ) , V_44 ) ) )
return - V_45 ;
* V_22 = & V_13 -> V_16 ;
V_13 -> V_25 = F_30 ( V_24 , V_41 << V_26 ,
& V_13 -> V_27 , V_44 ,
& V_9 -> V_28 ) ;
if ( ! V_13 -> V_25 ) {
F_31 ( V_17 , L_1 ) ;
return - V_45 ;
}
if ( F_10 ( V_13 -> V_27 & ( V_42 - 1 ) ) )
F_32 ( V_17 ,
L_2 ,
& V_13 -> V_27 , V_42 ) ;
V_13 -> V_31 . type = 12 ;
V_13 -> V_31 . V_6 = V_13 -> V_27 >> 12 ;
V_13 -> V_31 . V_46 = ( V_41 << V_26 ) >> 12 ;
V_13 -> V_16 . V_5 . V_6 = V_13 -> V_27 ;
F_33 ( & V_13 -> V_16 . V_5 . V_33 ) ;
F_34 ( & V_13 -> V_31 . V_34 , & V_13 -> V_16 . V_5 . V_33 ) ;
return 0 ;
}
static int
F_35 ( struct V_8 * V_9 , T_3 V_41 , T_3 V_42 ,
struct F_3 * * V_22 )
{
struct V_29 * V_13 ;
struct V_43 * V_17 = & V_9 -> V_16 . V_17 ;
struct V_30 * V_31 ;
int V_47 ;
int V_32 ;
if ( ! ( V_13 = F_29 ( sizeof( * V_13 ) +
sizeof( V_13 -> V_38 [ 0 ] ) * V_41 , V_44 ) ) )
return - V_45 ;
* V_22 = & V_13 -> V_16 ;
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ ) {
struct V_48 * V_49 = F_36 ( V_44 ) ;
if ( V_49 == NULL ) {
V_47 = - V_45 ;
goto V_50;
}
V_13 -> V_38 [ V_32 ] = V_49 ;
}
F_24 ( V_9 -> V_39 ) ;
V_47 = F_37 ( V_9 -> V_40 , 0 , 1 , V_41 , V_41 ,
V_42 >> V_9 -> V_35 , & V_31 ) ;
F_26 ( V_9 -> V_39 ) ;
if ( V_47 ) {
F_31 ( V_17 , L_3 ) ;
goto V_50;
}
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ ) {
struct V_48 * V_49 = V_13 -> V_38 [ V_32 ] ;
T_3 V_6 = ( V_31 -> V_6 + V_32 ) << V_9 -> V_35 ;
V_47 = F_38 ( V_9 -> V_36 , V_6 , F_39 ( V_49 ) ,
V_37 , V_51 | V_52 ) ;
if ( V_47 < 0 ) {
F_31 ( V_17 , L_4 , V_47 ) ;
while ( V_32 -- > 0 ) {
V_6 -= V_37 ;
F_22 ( V_9 -> V_36 , V_6 , V_37 ) ;
}
goto V_53;
}
}
V_31 -> V_6 |= F_21 ( 34 - V_9 -> V_35 ) ;
V_13 -> V_16 . V_5 . V_6 = ( ( T_1 ) V_31 -> V_6 ) << V_9 -> V_35 ;
F_33 ( & V_13 -> V_16 . V_5 . V_33 ) ;
F_34 ( & V_31 -> V_34 , & V_13 -> V_16 . V_5 . V_33 ) ;
return 0 ;
V_53:
F_24 ( V_9 -> V_39 ) ;
F_25 ( V_9 -> V_40 , & V_31 ) ;
F_26 ( V_9 -> V_39 ) ;
V_50:
for ( V_32 = 0 ; V_32 < V_41 && V_13 -> V_38 [ V_32 ] != NULL ; V_32 ++ )
F_23 ( V_13 -> V_38 [ V_32 ] ) ;
return V_47 ;
}
static int
F_40 ( struct V_54 * V_16 , T_3 V_7 , T_3 V_42 , bool V_55 ,
struct V_2 * * V_56 )
{
struct V_8 * V_9 = V_8 ( V_16 ) ;
struct F_3 * V_13 = NULL ;
struct V_43 * V_17 = & V_9 -> V_16 . V_17 ;
int V_47 ;
F_41 ( V_17 , L_5 , V_57 ,
V_9 -> V_36 ? L_6 : L_7 , V_7 , V_42 ) ;
V_7 = F_42 ( F_43 ( V_7 , V_37 ) , V_37 ) ;
V_42 = F_42 ( F_43 ( V_42 , V_37 ) , V_37 ) ;
if ( V_9 -> V_36 )
V_47 = F_35 ( V_9 , V_7 >> V_26 ,
V_42 , & V_13 ) ;
else
V_47 = F_28 ( V_9 , V_7 >> V_26 ,
V_42 , & V_13 ) ;
* V_56 = V_13 ? & V_13 -> V_3 : NULL ;
if ( V_47 )
return V_47 ;
F_44 ( & V_58 , & V_13 -> V_3 ) ;
V_13 -> V_9 = V_9 ;
V_13 -> V_5 . V_7 = V_7 >> 12 ;
V_13 -> V_5 . V_59 = 0 ;
V_13 -> V_5 . V_60 = 12 ;
F_41 ( V_17 , L_8 ,
V_7 , V_42 , V_13 -> V_5 . V_6 ) ;
return 0 ;
}
static void
F_45 ( struct V_54 * V_16 )
{
V_8 ( V_16 ) -> V_18 = ~ 0ULL ;
}
int
F_46 ( struct V_14 * V_15 , int V_61 ,
struct V_54 * * V_62 )
{
struct V_63 * V_64 = V_15 -> V_65 -> V_66 ( V_15 ) ;
struct V_8 * V_9 ;
if ( ! ( V_9 = F_29 ( sizeof( * V_9 ) , V_44 ) ) )
return - V_45 ;
F_47 ( & V_8 , V_15 , V_61 , & V_9 -> V_16 ) ;
F_48 ( & V_9 -> V_11 ) ;
* V_62 = & V_9 -> V_16 ;
if ( V_64 -> V_67 . V_36 ) {
V_9 -> V_36 = V_64 -> V_67 . V_36 ;
V_9 -> V_40 = & V_64 -> V_67 . V_40 ;
V_9 -> V_35 = V_64 -> V_67 . V_68 ;
V_9 -> V_39 = & V_64 -> V_67 . V_69 ;
F_49 ( & V_9 -> V_16 . V_17 , L_9 ) ;
} else {
F_50 ( & V_9 -> V_28 ) ;
F_51 ( V_70 , & V_9 -> V_28 ) ;
F_51 ( V_71 , & V_9 -> V_28 ) ;
F_51 ( V_72 , & V_9 -> V_28 ) ;
F_51 ( V_73 , & V_9 -> V_28 ) ;
F_49 ( & V_9 -> V_16 . V_17 , L_10 ) ;
}
return 0 ;
}
