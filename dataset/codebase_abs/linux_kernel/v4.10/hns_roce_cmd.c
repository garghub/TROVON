static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 . V_5 + V_6 ) ;
return ( ! ! ( V_3 & ( 1 << V_7 ) ) ) ;
}
static int F_3 ( struct V_1 * V_2 ,
T_2 V_8 , T_2 V_9 ,
T_1 V_10 , T_3 V_11 , T_4 V_12 ,
T_4 V_13 , int V_14 )
{
struct V_15 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_17 = & V_2 -> V_18 -> V_17 ;
T_1 T_5 * V_5 = ( T_1 * ) V_4 -> V_5 ;
int V_19 = - V_20 ;
unsigned long V_21 ;
T_1 V_22 = 0 ;
V_21 = F_4 ( V_23 ) + V_24 ;
while ( F_1 ( V_2 ) ) {
if ( F_5 ( V_24 , V_21 ) ) {
F_6 ( V_17 , L_1 , ( int ) V_24 ,
( int ) V_21 ) ;
goto V_25;
}
F_7 () ;
}
F_8 ( V_22 , V_26 , V_27 ,
V_12 ) ;
F_8 ( V_22 , V_28 ,
V_29 , V_11 ) ;
F_9 ( V_22 , V_30 , V_14 ) ;
F_9 ( V_22 , V_31 , 1 ) ;
F_8 ( V_22 , V_32 ,
V_33 , V_13 ) ;
F_10 ( F_11 ( V_8 ) , V_5 + 0 ) ;
F_10 ( F_11 ( V_9 ) , V_5 + 2 ) ;
F_12 ( F_13 ( V_10 ) , V_5 + 4 ) ;
F_14 () ;
F_12 ( F_13 ( V_22 ) , V_5 + 5 ) ;
F_15 () ;
V_19 = 0 ;
V_25:
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_8 ,
T_2 V_9 , T_1 V_10 ,
T_3 V_11 , T_4 V_12 , T_4 V_13 ,
int V_14 )
{
struct V_15 * V_4 = & V_2 -> V_4 ;
int V_19 = - V_20 ;
F_17 ( & V_4 -> V_34 ) ;
V_19 = F_3 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 , V_13 ,
V_14 ) ;
F_18 ( & V_4 -> V_34 ) ;
return V_19 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_8 ,
T_2 V_9 , unsigned long V_10 ,
T_3 V_11 , T_4 V_12 ,
unsigned long V_35 )
{
struct V_16 * V_17 = & V_2 -> V_18 -> V_17 ;
T_3 T_5 * V_5 = V_2 -> V_4 . V_5 ;
unsigned long V_21 = 0 ;
T_1 V_3 = 0 ;
int V_19 ;
V_19 = F_16 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 ,
V_36 , 0 ) ;
if ( V_19 ) {
F_20 ( V_17 , L_2 ) ;
goto V_25;
}
V_21 = F_4 ( V_35 ) + V_24 ;
while ( F_1 ( V_2 ) && F_21 ( V_24 , V_21 ) )
F_7 () ;
if ( F_1 ( V_2 ) ) {
F_20 ( V_17 , L_3 ) ;
V_19 = - V_37 ;
goto V_25;
}
V_3 = F_22 ( ( V_38 V_39 )
F_23 ( V_5 + V_40 ) ) ;
if ( ( V_3 & V_41 ) != 0x1 ) {
F_20 ( V_17 , L_4 , V_3 ) ;
V_19 = - V_42 ;
goto V_25;
}
V_25:
return V_19 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 V_8 ,
T_2 V_9 , unsigned long V_10 ,
T_3 V_11 , T_4 V_12 , unsigned long V_35 )
{
int V_19 ;
F_25 ( & V_2 -> V_4 . V_43 ) ;
V_19 = F_19 ( V_2 , V_8 , V_9 , V_10 ,
V_11 , V_12 , V_35 ) ;
F_26 ( & V_2 -> V_4 . V_43 ) ;
return V_19 ;
}
void F_27 ( struct V_1 * V_2 , T_4 V_13 , T_3 V_3 ,
T_2 V_9 )
{
struct V_44
* V_45 = & V_2 -> V_4 . V_45 [ V_13 & V_2 -> V_4 . V_46 ] ;
if ( V_13 != V_45 -> V_13 )
return;
V_45 -> V_47 = ( V_3 == V_48 ) ? 0 : ( - V_49 ) ;
V_45 -> V_9 = V_9 ;
F_28 ( & V_45 -> V_50 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_8 ,
T_2 V_9 , unsigned long V_10 ,
T_3 V_11 , T_4 V_12 ,
unsigned long V_35 )
{
struct V_15 * V_4 = & V_2 -> V_4 ;
struct V_16 * V_17 = & V_2 -> V_18 -> V_17 ;
struct V_44 * V_45 ;
int V_19 = 0 ;
F_30 ( & V_4 -> V_51 ) ;
F_31 ( V_4 -> V_52 < 0 ) ;
V_45 = & V_4 -> V_45 [ V_4 -> V_52 ] ;
V_45 -> V_13 += V_4 -> V_46 + 1 ;
V_4 -> V_52 = V_45 -> V_53 ;
F_32 ( & V_4 -> V_51 ) ;
F_33 ( & V_45 -> V_50 ) ;
V_19 = F_16 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 ,
V_45 -> V_13 , 1 ) ;
if ( V_19 )
goto V_25;
if ( ! F_34 ( & V_45 -> V_50 ,
F_4 ( V_35 ) ) ) {
F_20 ( V_17 , L_5 ) ;
V_19 = - V_42 ;
goto V_25;
}
V_19 = V_45 -> V_47 ;
if ( V_19 ) {
F_20 ( V_17 , L_6 , V_19 ) ;
goto V_25;
}
V_25:
F_30 ( & V_4 -> V_51 ) ;
V_45 -> V_53 = V_4 -> V_52 ;
V_4 -> V_52 = V_45 - V_4 -> V_45 ;
F_32 ( & V_4 -> V_51 ) ;
return V_19 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 V_8 ,
T_2 V_9 , unsigned long V_10 ,
T_3 V_11 , T_4 V_12 , unsigned long V_35 )
{
int V_19 = 0 ;
F_25 ( & V_2 -> V_4 . V_54 ) ;
V_19 = F_29 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 , V_35 ) ;
F_26 ( & V_2 -> V_4 . V_54 ) ;
return V_19 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_8 , T_2 V_9 ,
unsigned long V_10 , T_3 V_11 , T_4 V_12 ,
unsigned long V_35 )
{
if ( V_2 -> V_4 . V_55 )
return F_35 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 ,
V_35 ) ;
else
return F_24 ( V_2 , V_8 , V_9 ,
V_10 , V_11 , V_12 ,
V_35 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_18 -> V_17 ;
F_38 ( & V_2 -> V_4 . V_34 ) ;
F_39 ( & V_2 -> V_4 . V_43 , 1 ) ;
V_2 -> V_4 . V_55 = 0 ;
V_2 -> V_4 . V_56 = 1 ;
V_2 -> V_4 . V_57 = V_58 ;
V_2 -> V_4 . V_5 = V_2 -> V_59 + V_60 ;
V_2 -> V_4 . V_61 = F_40 ( L_7 , V_17 ,
V_62 ,
V_62 , 0 ) ;
if ( ! V_2 -> V_4 . V_61 )
return - V_63 ;
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 -> V_4 . V_61 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_15 * V_64 = & V_2 -> V_4 ;
int V_65 ;
V_64 -> V_45 = F_44 ( V_64 -> V_57 *
sizeof( struct V_44 ) ,
V_66 ) ;
if ( ! V_64 -> V_45 )
return - V_63 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_57 ; ++ V_65 ) {
V_64 -> V_45 [ V_65 ] . V_13 = V_65 ;
V_64 -> V_45 [ V_65 ] . V_53 = V_65 + 1 ;
}
V_64 -> V_45 [ V_64 -> V_57 - 1 ] . V_53 = - 1 ;
V_64 -> V_52 = 0 ;
F_39 ( & V_64 -> V_54 , V_64 -> V_57 ) ;
F_45 ( & V_64 -> V_51 ) ;
V_64 -> V_46 = V_67 ;
V_64 -> V_55 = 1 ;
F_25 ( & V_64 -> V_43 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_15 * V_64 = & V_2 -> V_4 ;
int V_65 ;
V_64 -> V_55 = 0 ;
for ( V_65 = 0 ; V_65 < V_64 -> V_57 ; ++ V_65 )
F_25 ( & V_64 -> V_54 ) ;
F_47 ( V_64 -> V_45 ) ;
F_26 ( & V_64 -> V_43 ) ;
}
struct V_68
* F_48 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
V_69 = F_44 ( sizeof( * V_69 ) , V_66 ) ;
if ( ! V_69 )
return F_49 ( - V_63 ) ;
V_69 -> V_70 = F_50 ( V_2 -> V_4 . V_61 , V_66 ,
& V_69 -> V_71 ) ;
if ( ! V_69 -> V_70 ) {
F_47 ( V_69 ) ;
return F_49 ( - V_63 ) ;
}
return V_69 ;
}
void F_51 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
if ( ! V_69 )
return;
F_52 ( V_2 -> V_4 . V_61 , V_69 -> V_70 , V_69 -> V_71 ) ;
F_47 ( V_69 ) ;
}
