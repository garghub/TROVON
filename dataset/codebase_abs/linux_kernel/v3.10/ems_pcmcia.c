static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
struct V_10 * V_11 ;
T_2 V_12 = V_13 ;
int V_14 , V_15 ;
if ( F_6 ( V_9 -> V_16 ) != 0xAA55 )
return V_17 ;
do {
V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_9 -> V_18 ; V_14 ++ ) {
V_11 = V_9 -> V_19 [ V_14 ] ;
if ( ! V_11 )
continue;
if ( F_7 ( V_6 , V_11 ) == V_17 )
V_15 = 1 ;
}
if ( V_15 )
V_12 = V_17 ;
} while ( V_15 );
return V_12 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_20 , 1 ) ;
F_3 ( V_2 , V_21 , V_22 ) ;
if ( F_1 ( V_2 , V_21 ) == V_22 )
return 1 ;
return 0 ;
}
static void F_9 ( struct V_23 * V_24 )
{
struct V_8 * V_9 = V_24 -> V_2 ;
struct V_10 * V_11 ;
int V_14 ;
F_10 ( V_24 -> V_6 , V_9 ) ;
for ( V_14 = 0 ; V_14 < V_9 -> V_18 ; V_14 ++ ) {
V_11 = V_9 -> V_19 [ V_14 ] ;
if ( ! V_11 )
continue;
F_11 ( V_25 L_1 ,
V_26 , V_11 -> V_27 , V_14 ) ;
F_12 ( V_11 ) ;
F_13 ( V_11 ) ;
}
F_4 ( V_28 , V_9 -> V_16 ) ;
F_14 ( V_9 -> V_16 ) ;
F_15 ( V_9 ) ;
V_24 -> V_2 = NULL ;
}
static int F_16 ( struct V_23 * V_24 , unsigned long V_29 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_30 , V_14 ;
V_9 = F_17 ( sizeof( struct V_8 ) , V_31 ) ;
if ( ! V_9 )
return - V_32 ;
V_24 -> V_2 = V_9 ;
V_9 -> V_18 = 0 ;
V_9 -> V_16 = F_18 ( V_29 , V_33 ) ;
if ( ! V_9 -> V_16 ) {
V_30 = - V_32 ;
goto V_34;
}
if ( F_6 ( V_9 -> V_16 ) != 0xAA55 ) {
V_30 = - V_35 ;
goto V_34;
}
F_4 ( V_36 , V_9 -> V_16 ) ;
F_4 ( V_37 , V_9 -> V_16 ) ;
for ( V_14 = 0 ; V_14 < V_38 ; V_14 ++ ) {
V_11 = F_19 ( 0 ) ;
if ( ! V_11 ) {
V_30 = - V_32 ;
goto V_34;
}
V_9 -> V_19 [ V_14 ] = V_11 ;
V_2 = F_20 ( V_11 ) ;
V_2 -> V_2 = V_9 ;
F_21 ( V_11 , & V_24 -> V_11 ) ;
V_2 -> V_39 = V_40 ;
V_11 -> V_6 = V_24 -> V_6 ;
V_2 -> V_4 = V_9 -> V_16 + V_41 +
( V_14 * V_42 ) ;
if ( F_8 ( V_2 ) ) {
V_2 -> V_43 = F_1 ;
V_2 -> V_44 = F_3 ;
V_2 -> V_45 . clock . V_46 = V_47 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = V_51 ;
V_2 -> V_52 |= V_53 ;
V_30 = F_22 ( V_11 ) ;
if ( V_30 ) {
F_13 ( V_11 ) ;
goto V_34;
}
V_9 -> V_18 ++ ;
F_11 ( V_25 L_2
L_3 , V_26 , V_11 -> V_27 ,
V_14 , V_2 -> V_4 , V_11 -> V_6 ) ;
} else
F_13 ( V_11 ) ;
}
V_30 = F_23 ( V_11 -> V_6 , & F_5 , V_40 ,
V_26 , V_9 ) ;
if ( ! V_30 )
return 0 ;
V_34:
F_9 ( V_24 ) ;
return V_30 ;
}
static int F_24 ( struct V_23 * V_11 )
{
int V_54 ;
V_11 -> V_55 |= V_56 ;
V_11 -> V_57 = 1 ;
V_11 -> V_58 = V_59 ;
V_11 -> V_60 [ 0 ] -> V_61 = 16 ;
V_11 -> V_60 [ 0 ] -> V_52 |= V_62 ;
V_11 -> V_60 [ 1 ] -> V_61 = 16 ;
V_11 -> V_60 [ 1 ] -> V_52 |= V_63 ;
V_11 -> V_64 = 5 ;
V_11 -> V_60 [ 2 ] -> V_52 =
( V_65 | V_66 | V_67 ) ;
V_11 -> V_60 [ 2 ] -> V_68 = V_11 -> V_60 [ 2 ] -> V_61 = 0 ;
V_54 = F_25 ( V_11 , V_11 -> V_60 [ 2 ] , 0 ) ;
if ( V_54 ) {
F_26 ( & V_11 -> V_11 , L_4 ,
V_54 ) ;
return 0 ;
}
V_54 = F_27 ( V_11 , V_11 -> V_60 [ 2 ] , V_11 -> V_69 ) ;
if ( V_54 ) {
F_26 ( & V_11 -> V_11 , L_5 ,
V_54 ) ;
return 0 ;
}
V_54 = F_28 ( V_11 ) ;
if ( V_54 ) {
F_26 ( & V_11 -> V_11 , L_6 ,
V_54 ) ;
return 0 ;
}
F_16 ( V_11 , V_11 -> V_60 [ 2 ] -> V_68 ) ;
return 0 ;
}
static void F_29 ( struct V_23 * V_11 )
{
F_9 ( V_11 ) ;
F_30 ( V_11 ) ;
}
