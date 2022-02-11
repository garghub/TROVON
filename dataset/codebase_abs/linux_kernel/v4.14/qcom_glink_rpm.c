static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
unsigned int V_6 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_6 = F_3 ( V_4 -> V_6 ) ;
if ( V_5 < V_6 )
return V_4 -> V_7 . V_8 - V_6 + V_5 ;
else
return V_5 - V_6 ;
}
static void F_4 ( struct V_1 * V_2 ,
void * V_9 , unsigned int V_10 , T_1 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_6 ;
T_1 V_12 ;
V_6 = F_3 ( V_4 -> V_6 ) ;
V_6 += V_10 ;
if ( V_6 >= V_4 -> V_7 . V_8 )
V_6 -= V_4 -> V_7 . V_8 ;
V_12 = F_5 ( T_1 , V_11 , V_4 -> V_7 . V_8 - V_6 ) ;
if ( V_12 ) {
F_6 ( V_9 , V_4 -> V_13 + V_6 ,
V_12 / sizeof( V_14 ) ) ;
}
if ( V_12 != V_11 ) {
F_6 ( V_9 + V_12 , V_4 -> V_13 ,
( V_11 - V_12 ) / sizeof( V_14 ) ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_6 ;
V_6 = F_3 ( V_4 -> V_6 ) ;
V_6 += V_11 ;
if ( V_6 >= V_4 -> V_7 . V_8 )
V_6 -= V_4 -> V_7 . V_8 ;
F_8 ( V_6 , V_4 -> V_6 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
unsigned int V_6 ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_6 = F_3 ( V_4 -> V_6 ) ;
if ( V_6 <= V_5 )
return V_4 -> V_7 . V_8 - V_5 + V_6 ;
else
return V_6 - V_5 ;
}
static unsigned int F_10 ( struct V_3 * V_4 ,
unsigned int V_5 ,
const void * V_9 , T_1 V_11 )
{
T_1 V_12 ;
V_12 = F_5 ( T_1 , V_11 , V_4 -> V_7 . V_8 - V_5 ) ;
if ( V_12 ) {
F_11 ( V_4 -> V_13 + V_5 , V_9 ,
V_12 / sizeof( V_14 ) ) ;
}
if ( V_12 != V_11 ) {
F_11 ( V_4 -> V_13 , V_9 + V_12 ,
( V_11 - V_12 ) / sizeof( V_14 ) ) ;
}
V_5 += V_11 ;
if ( V_5 >= V_4 -> V_7 . V_8 )
V_5 -= V_4 -> V_7 . V_8 ;
return V_5 ;
}
static void F_12 ( struct V_1 * V_2 ,
const void * V_15 , T_1 V_16 ,
const void * V_9 , T_1 V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_18 = V_16 + V_17 ;
T_1 V_19 ;
unsigned int V_5 ;
char V_20 [ 8 ] = { 0 } ;
T_1 V_21 ;
if ( F_13 ( V_16 % 4 , L_1 ) )
return;
V_19 = F_14 ( V_17 , 4 ) ;
if ( V_19 != V_17 )
memcpy ( V_20 , V_9 + V_19 , V_17 - V_19 ) ;
V_5 = F_3 ( V_4 -> V_5 ) ;
V_5 = F_10 ( V_4 , V_5 , V_15 , V_16 ) ;
V_5 = F_10 ( V_4 , V_5 , V_9 , V_19 ) ;
V_21 = F_15 ( V_18 , 8 ) - F_14 ( V_18 , 4 ) ;
if ( V_21 )
V_5 = F_10 ( V_4 , V_5 , V_20 , V_21 ) ;
F_8 ( V_5 , V_4 -> V_5 ) ;
}
static int F_16 ( struct V_22 * V_23 ,
void T_2 * V_24 ,
T_1 V_25 ,
struct V_3 * V_26 ,
struct V_3 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
unsigned int V_31 ;
T_1 V_10 ;
T_1 V_32 ;
void * V_33 ;
int V_34 ;
V_33 = F_17 ( V_35 , V_36 ) ;
if ( ! V_33 )
return - V_37 ;
F_6 ( V_33 , V_24 + V_25 - V_35 ,
V_35 / sizeof( V_14 ) ) ;
V_29 = V_33 ;
if ( F_18 ( V_29 -> V_38 ) != V_39 ) {
F_19 ( V_23 , L_2 ) ;
goto V_40;
}
V_30 = F_18 ( V_29 -> V_11 ) ;
if ( V_30 > V_41 ) {
F_19 ( V_23 , L_3 ) ;
goto V_40;
}
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
V_31 = F_18 ( V_29 -> V_42 [ V_34 ] . V_31 ) ;
V_10 = F_18 ( V_29 -> V_42 [ V_34 ] . V_10 ) ;
V_32 = F_18 ( V_29 -> V_42 [ V_34 ] . V_32 ) ;
if ( V_10 > V_25 || V_10 + V_32 > V_25 ) {
F_19 ( V_23 , L_4 ) ;
continue;
}
switch ( V_31 ) {
case V_43 :
V_26 -> V_7 . V_8 = V_32 ;
V_26 -> V_6 = V_24 + V_10 ;
V_26 -> V_5 = V_24 + V_10 + sizeof( V_14 ) ;
V_26 -> V_13 = V_24 + V_10 + 2 * sizeof( V_14 ) ;
break;
case V_44 :
V_27 -> V_7 . V_8 = V_32 ;
V_27 -> V_6 = V_24 + V_10 ;
V_27 -> V_5 = V_24 + V_10 + sizeof( V_14 ) ;
V_27 -> V_13 = V_24 + V_10 + 2 * sizeof( V_14 ) ;
break;
}
}
if ( ! V_26 -> V_13 || ! V_27 -> V_13 ) {
F_19 ( V_23 , L_5 ) ;
goto V_40;
}
F_20 ( V_33 ) ;
return 0 ;
V_40:
F_20 ( V_33 ) ;
return - V_45 ;
}
static int F_21 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_3 * V_50 ;
struct V_3 * V_51 ;
struct V_52 * V_53 ;
void T_2 * V_24 ;
T_1 V_25 ;
struct V_22 * V_23 = & V_47 -> V_23 ;
struct V_54 V_55 ;
int V_56 ;
V_50 = F_22 ( & V_47 -> V_23 , sizeof( * V_50 ) , V_36 ) ;
V_51 = F_22 ( & V_47 -> V_23 , sizeof( * V_51 ) , V_36 ) ;
if ( ! V_50 || ! V_51 )
return - V_37 ;
V_53 = F_23 ( V_23 -> V_57 , L_6 , 0 ) ;
V_56 = F_24 ( V_53 , 0 , & V_55 ) ;
F_25 ( V_53 ) ;
if ( V_56 )
return V_56 ;
V_24 = F_26 ( V_23 , V_55 . V_58 , F_27 ( & V_55 ) ) ;
V_25 = F_27 ( & V_55 ) ;
if ( ! V_24 )
return - V_37 ;
V_56 = F_16 ( V_23 , V_24 , V_25 ,
V_50 , V_51 ) ;
if ( V_56 )
return V_56 ;
V_50 -> V_7 . V_59 = F_1 ;
V_50 -> V_7 . V_60 = F_4 ;
V_50 -> V_7 . V_61 = F_7 ;
V_51 -> V_7 . V_59 = F_9 ;
V_51 -> V_7 . V_62 = F_12 ;
F_8 ( 0 , V_51 -> V_5 ) ;
F_8 ( 0 , V_50 -> V_6 ) ;
V_49 = F_28 ( & V_47 -> V_23 ,
0 ,
& V_50 -> V_7 ,
& V_51 -> V_7 ,
true ) ;
if ( F_29 ( V_49 ) )
return F_30 ( V_49 ) ;
F_31 ( V_47 , V_49 ) ;
return 0 ;
}
static int F_32 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_33 ( V_47 ) ;
F_34 ( V_49 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
return F_36 ( & V_63 ) ;
}
static void T_4 F_37 ( void )
{
F_38 ( & V_63 ) ;
}
