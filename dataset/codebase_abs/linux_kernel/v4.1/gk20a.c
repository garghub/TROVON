static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
unsigned long V_8 ;
T_2 V_9 = ( V_7 -> V_10 -> V_3 + V_3 ) & 0xffffff00000ULL ;
T_2 V_11 = ( V_7 -> V_10 -> V_3 + V_3 ) & 0x000000fffffULL ;
T_1 V_12 ;
F_3 ( & V_5 -> V_13 , V_8 ) ;
if ( F_4 ( V_5 -> V_11 != V_9 ) ) {
F_5 ( V_5 , 0x001700 , V_9 >> 16 ) ;
V_5 -> V_11 = V_9 ;
}
V_12 = F_6 ( V_5 , 0x700000 + V_11 ) ;
F_7 ( & V_5 -> V_13 , V_8 ) ;
return V_12 ;
}
static void
F_8 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_12 )
{
struct V_4 * V_5 = ( void * ) F_2 ( V_2 ) ;
struct V_6 * V_7 = ( void * ) V_2 ;
unsigned long V_8 ;
T_2 V_9 = ( V_7 -> V_10 -> V_3 + V_3 ) & 0xffffff00000ULL ;
T_2 V_11 = ( V_7 -> V_10 -> V_3 + V_3 ) & 0x000000fffffULL ;
F_3 ( & V_5 -> V_13 , V_8 ) ;
if ( F_4 ( V_5 -> V_11 != V_9 ) ) {
F_5 ( V_5 , 0x001700 , V_9 >> 16 ) ;
V_5 -> V_11 = V_9 ;
}
F_5 ( V_5 , 0x700000 + V_11 , V_12 ) ;
F_7 ( & V_5 -> V_13 , V_8 ) ;
}
static void
F_9 ( struct V_6 * V_14 )
{
struct V_15 * V_7 = ( void * ) V_14 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_7 ) ;
struct V_16 * V_17 = F_10 ( F_11 ( V_5 ) ) ;
if ( F_4 ( ! V_7 -> V_18 ) )
return;
F_12 ( V_17 , V_14 -> V_10 -> V_19 << V_20 , V_7 -> V_18 ,
V_7 -> V_21 , & V_5 -> V_22 ) ;
}
static void
F_13 ( struct V_6 * V_14 )
{
struct V_23 * V_7 = ( void * ) V_14 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_7 ) ;
struct V_24 * V_25 ;
int V_26 ;
if ( F_4 ( F_14 ( & V_14 -> V_10 -> V_27 ) ) )
return;
V_25 = F_15 ( & V_14 -> V_10 -> V_27 , struct V_24 ,
V_28 ) ;
V_25 -> V_3 &= ~ F_16 ( 34 - V_5 -> V_29 ) ;
for ( V_26 = 0 ; V_26 < V_14 -> V_10 -> V_19 ; V_26 ++ ) {
F_17 ( V_5 -> V_30 ,
( V_25 -> V_3 + V_26 ) << V_5 -> V_29 , V_31 ) ;
F_18 ( V_7 -> V_32 [ V_26 ] ) ;
}
F_19 ( V_5 -> V_33 ) ;
F_20 ( V_5 -> V_34 , & V_25 ) ;
F_21 ( V_5 -> V_33 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_7 ) ;
if ( V_5 -> V_30 )
F_13 ( V_7 ) ;
else
F_9 ( V_7 ) ;
F_23 ( & V_7 -> V_9 ) ;
}
static int
F_24 ( struct V_1 * V_35 , struct V_1 * V_36 ,
struct V_37 * V_38 , T_1 V_39 , T_1 V_40 ,
struct V_6 * * V_14 )
{
struct V_15 * V_7 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_35 ) ;
struct V_16 * V_17 = F_10 ( F_11 ( V_35 ) ) ;
int V_41 ;
V_41 = F_25 ( V_35 , V_36 , V_38 , sizeof( * V_7 ) ,
( void * * ) & V_7 ) ;
* V_14 = & V_7 -> V_9 ;
if ( V_41 )
return V_41 ;
V_7 -> V_18 = F_26 ( V_17 , V_39 << V_20 ,
& V_7 -> V_21 , V_42 ,
& V_5 -> V_22 ) ;
if ( ! V_7 -> V_18 ) {
F_27 ( V_5 , L_1 ) ;
return - V_43 ;
}
if ( F_4 ( V_7 -> V_21 & ( V_40 - 1 ) ) )
F_28 ( V_5 , L_2 ,
& V_7 -> V_21 , V_40 ) ;
V_7 -> V_25 . type = 12 ;
V_7 -> V_25 . V_3 = V_7 -> V_21 >> 12 ;
V_7 -> V_25 . V_44 = ( V_39 << V_20 ) >> 12 ;
V_7 -> V_9 . V_45 . V_3 = V_7 -> V_21 ;
F_29 ( & V_7 -> V_9 . V_45 . V_27 ) ;
F_30 ( & V_7 -> V_25 . V_28 , & V_7 -> V_9 . V_45 . V_27 ) ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_35 , struct V_1 * V_36 ,
struct V_37 * V_38 , T_1 V_39 , T_1 V_40 ,
struct V_6 * * V_14 )
{
struct V_23 * V_7 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_35 ) ;
struct V_24 * V_25 ;
int V_41 ;
int V_26 ;
V_41 = F_25 ( V_35 , V_36 , V_38 ,
sizeof( * V_7 ) + sizeof( V_7 -> V_32 [ 0 ] ) * V_39 ,
( void * * ) & V_7 ) ;
* V_14 = & V_7 -> V_9 ;
if ( V_41 )
return V_41 ;
for ( V_26 = 0 ; V_26 < V_39 ; V_26 ++ ) {
struct V_46 * V_47 = F_32 ( V_42 ) ;
if ( V_47 == NULL ) {
V_41 = - V_43 ;
goto V_48;
}
V_7 -> V_32 [ V_26 ] = V_47 ;
}
F_19 ( V_5 -> V_33 ) ;
V_41 = F_33 ( V_5 -> V_34 , 0 , 1 , V_39 , V_39 ,
V_40 >> V_5 -> V_29 , & V_25 ) ;
F_21 ( V_5 -> V_33 ) ;
if ( V_41 ) {
F_27 ( V_5 , L_3 ) ;
goto V_48;
}
for ( V_26 = 0 ; V_26 < V_39 ; V_26 ++ ) {
struct V_46 * V_47 = V_7 -> V_32 [ V_26 ] ;
T_1 V_3 = ( V_25 -> V_3 + V_26 ) << V_5 -> V_29 ;
V_41 = F_34 ( V_5 -> V_30 , V_3 , F_35 ( V_47 ) ,
V_31 , V_49 | V_50 ) ;
if ( V_41 < 0 ) {
F_27 ( V_5 , L_4 , V_41 ) ;
while ( V_26 -- > 0 ) {
V_3 -= V_31 ;
F_17 ( V_5 -> V_30 , V_3 , V_31 ) ;
}
goto V_51;
}
}
V_25 -> V_3 |= F_16 ( 34 - V_5 -> V_29 ) ;
V_7 -> V_9 . V_45 . V_3 = ( ( T_2 ) V_25 -> V_3 ) << V_5 -> V_29 ;
F_29 ( & V_7 -> V_9 . V_45 . V_27 ) ;
F_30 ( & V_25 -> V_28 , & V_7 -> V_9 . V_45 . V_27 ) ;
return 0 ;
V_51:
F_19 ( V_5 -> V_33 ) ;
F_20 ( V_5 -> V_34 , & V_25 ) ;
F_21 ( V_5 -> V_33 ) ;
V_48:
for ( V_26 = 0 ; V_26 < V_39 && V_7 -> V_32 [ V_26 ] != NULL ; V_26 ++ )
F_18 ( V_7 -> V_32 [ V_26 ] ) ;
return V_41 ;
}
static int
F_36 ( struct V_1 * V_35 , struct V_1 * V_36 ,
struct V_37 * V_38 , void * V_12 , T_1 V_52 ,
struct V_1 * * V_53 )
{
struct V_54 * args = V_12 ;
struct V_4 * V_5 = ( void * ) F_2 ( V_35 ) ;
struct V_6 * V_7 ;
T_1 V_19 , V_40 ;
int V_41 ;
F_37 ( V_35 , L_5 , V_55 ,
V_5 -> V_30 ? L_6 : L_7 , args -> V_19 , args -> V_40 ) ;
V_19 = F_38 ( F_39 ( args -> V_19 , V_31 ) , V_31 ) ;
V_40 = F_38 ( F_39 ( args -> V_40 , V_31 ) , V_31 ) ;
if ( V_5 -> V_30 )
V_41 = F_31 ( V_35 , V_36 , V_38 ,
V_19 >> V_20 , V_40 , & V_7 ) ;
else
V_41 = F_24 ( V_35 , V_36 , V_38 ,
V_19 >> V_20 , V_40 , & V_7 ) ;
* V_53 = F_40 ( V_7 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_10 = & V_7 -> V_45 ;
V_7 -> V_10 -> V_19 = V_19 >> 12 ;
V_7 -> V_10 -> V_56 = 0 ;
V_7 -> V_10 -> V_57 = 12 ;
V_7 -> V_9 . V_11 = V_7 -> V_10 -> V_3 ;
V_7 -> V_9 . V_19 = V_19 ;
F_37 ( V_35 , L_8 ,
V_19 , V_40 , V_7 -> V_10 -> V_3 ) ;
return 0 ;
}
static int
F_41 ( struct V_1 * V_2 , bool V_58 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
V_5 -> V_11 = ~ 0ULL ;
return F_42 ( & V_5 -> V_9 , V_58 ) ;
}
static int
F_43 ( struct V_1 * V_35 , struct V_1 * V_36 ,
struct V_37 * V_38 , void * V_12 , T_1 V_19 ,
struct V_1 * * V_53 )
{
struct V_4 * V_5 ;
struct V_59 * V_60 ;
int V_41 ;
V_41 = F_44 ( V_35 , V_36 , V_38 , & V_5 ) ;
* V_53 = F_40 ( V_5 ) ;
if ( V_41 )
return V_41 ;
F_45 ( & V_5 -> V_13 ) ;
V_60 = F_46 ( F_11 ( V_35 ) ) ;
if ( V_60 -> V_61 -> V_62 . V_30 ) {
V_5 -> V_30 = V_60 -> V_61 -> V_62 . V_30 ;
V_5 -> V_34 = V_60 -> V_61 -> V_62 . V_34 ;
V_5 -> V_29 = V_60 -> V_61 -> V_62 . V_63 ;
V_5 -> V_33 = & V_60 -> V_61 -> V_62 . V_64 ;
F_47 ( V_5 , L_9 ) ;
} else {
F_48 ( & V_5 -> V_22 ) ;
F_49 ( V_65 , & V_5 -> V_22 ) ;
F_49 ( V_66 , & V_5 -> V_22 ) ;
F_49 ( V_67 , & V_5 -> V_22 ) ;
F_49 ( V_68 , & V_5 -> V_22 ) ;
F_47 ( V_5 , L_10 ) ;
}
return 0 ;
}
