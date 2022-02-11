static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_7 )
{
unsigned int V_8 ;
int V_9 , V_10 = 0 , V_11 ;
V_11 = V_12 - V_7 -> V_10 ;
V_10 = V_13 - V_7 -> V_10 ;
V_8 = V_14 | V_15 ;
for ( V_9 = ( V_11 + 1 ) ; V_9 <= V_12 ; V_9 ++ ) {
F_3 ( V_7 , F_6 ( V_9 ) ,
V_8 | F_7 ( V_10 ) ) ;
F_3 ( V_7 , F_8 ( V_9 ) ,
V_16 ) ;
V_10 ++ ;
}
F_3 ( V_7 , V_17 , V_18 ) ;
}
static int F_9 ( struct V_19 * V_20 , int V_10 )
{
struct V_21 * V_22 ;
int V_9 ;
V_20 -> V_23 = V_10 ;
V_22 = F_10 ( V_20 -> V_23 ,
sizeof( struct V_21 ) , V_24 ) ;
if ( V_22 == NULL )
return - V_25 ;
for ( V_9 = 0 ; V_9 < ( V_20 -> V_23 ) ; V_9 ++ ) {
struct V_21 * V_26 = V_22 + V_9 ;
V_26 -> type = V_27 ;
V_26 -> V_28 = 1 ;
V_26 -> V_29 = V_9 ;
V_26 -> V_30 = F_11 ( V_31 ) ;
}
V_20 -> V_10 = V_22 ;
return V_20 -> V_23 ;
}
static void F_12 ( struct V_19 * V_20 )
{
F_13 ( V_20 -> V_10 ) ;
}
static int F_14 ( struct V_19 * V_20 ,
struct V_21 const * V_26 ,
int * V_6 , int * V_32 , long V_33 )
{
struct V_1 * V_7 = F_15 ( V_20 ) ;
int V_9 ;
unsigned int V_34 , V_35 ;
V_34 = F_1 ( V_7 , V_36 ) ;
for ( V_9 = 0 ; V_9 < V_34 ; V_9 ++ ) {
V_35 = F_1 ( V_7 , V_37 ) ;
if ( V_9 == V_26 -> V_29 )
* V_6 = V_35 & 0xfff ;
}
F_3 ( V_7 , V_17 , V_18 ) ;
return V_38 ;
}
static int F_16 ( struct V_39 * V_40 )
{
struct V_19 * V_20 ;
struct V_1 * V_7 ;
struct V_41 * V_42 = V_40 -> V_43 . V_44 ;
struct V_45 * V_46 ;
int V_47 ;
V_46 = V_42 -> V_43 -> V_44 ;
if ( ! V_46 || ! V_46 -> V_48 ) {
F_17 ( & V_40 -> V_43 , L_1 ) ;
return - V_49 ;
}
V_20 = F_18 ( sizeof( struct V_1 ) ) ;
if ( V_20 == NULL ) {
F_17 ( & V_40 -> V_43 , L_2 ) ;
V_47 = - V_25 ;
goto V_50;
}
V_7 = F_15 ( V_20 ) ;
V_7 -> V_4 = V_42 ;
V_7 -> V_10 = V_46 -> V_48 -> V_51 ;
V_20 -> V_43 . V_52 = & V_40 -> V_43 ;
V_20 -> V_53 = F_19 ( & V_40 -> V_43 ) ;
V_20 -> V_54 = V_55 ;
V_20 -> V_56 = & V_57 ;
F_5 ( V_7 ) ;
V_47 = F_9 ( V_20 , V_7 -> V_10 ) ;
if ( V_47 < 0 )
goto V_58;
V_47 = F_20 ( V_20 ) ;
if ( V_47 )
goto V_59;
F_21 ( V_40 , V_20 ) ;
return 0 ;
V_59:
F_12 ( V_20 ) ;
V_58:
F_22 ( V_20 ) ;
V_50:
return V_47 ;
}
static int F_23 ( struct V_39 * V_40 )
{
struct V_19 * V_20 = F_24 ( V_40 ) ;
F_25 ( V_20 ) ;
F_12 ( V_20 ) ;
F_22 ( V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_43 )
{
struct V_19 * V_20 = F_27 ( V_43 ) ;
struct V_1 * V_7 = F_15 ( V_20 ) ;
struct V_41 * V_42 = V_43 -> V_44 ;
unsigned int V_61 ;
if ( ! F_28 ( V_42 -> V_43 ) ) {
V_61 = F_1 ( V_7 , V_62 ) ;
V_61 &= ~ ( V_63 ) ;
F_3 ( V_7 , V_62 , ( V_61 |
V_64 ) ) ;
}
return 0 ;
}
static int F_29 ( struct V_60 * V_43 )
{
struct V_19 * V_20 = F_27 ( V_43 ) ;
struct V_1 * V_7 = F_15 ( V_20 ) ;
unsigned int V_65 ;
V_65 = F_1 ( V_7 , V_62 ) ;
V_65 &= ~ ( V_64 ) ;
F_3 ( V_7 , V_62 , V_65 ) ;
F_5 ( V_7 ) ;
return 0 ;
}
