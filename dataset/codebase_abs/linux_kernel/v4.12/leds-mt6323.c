static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_11 -> V_10 ;
T_1 V_12 = 0 , V_13 = 0 ;
int V_14 ;
V_12 |= V_15 |
V_16 |
V_17 ;
V_13 |= F_3 ( V_4 - 1 ) |
F_4 ( 2 ) |
V_18 ;
V_14 = F_5 ( V_10 , F_6 ( V_6 -> V_19 ) ,
V_12 , V_13 ) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_11 -> V_10 ;
unsigned int V_20 ;
int V_14 ;
V_20 = F_8 ( V_6 -> V_19 ) ;
V_14 = F_5 ( V_10 , V_21 ,
F_9 ( V_6 -> V_19 ) , ~ V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
F_10 ( 100 , 300 ) ;
V_14 = F_5 ( V_10 , V_22 ,
F_11 ( V_6 -> V_19 ) ,
F_12 ( V_6 -> V_19 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static enum V_3
F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_11 -> V_10 ;
unsigned int V_20 ;
int V_14 ;
V_14 = F_14 ( V_10 , V_22 , & V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_20 & F_11 ( V_6 -> V_19 ) )
return 0 ;
V_14 = F_14 ( V_10 , V_21 , & V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( ! ( V_20 & F_8 ( V_6 -> V_19 ) ) )
return 0 ;
V_14 = F_14 ( V_10 , F_6 ( V_6 -> V_19 ) , & V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
return ( ( V_20 & V_15 )
>> V_23 ) + 1 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_11 -> V_10 ;
unsigned int V_20 ;
int V_14 ;
V_14 = F_5 ( V_10 , V_24 ,
F_16 ( V_6 -> V_19 ) , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_20 = F_12 ( V_6 -> V_19 ) ;
V_14 = F_5 ( V_10 , V_22 ,
F_11 ( V_6 -> V_19 ) ,
~ V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
F_10 ( 100 , 300 ) ;
V_14 = F_5 ( V_10 , V_21 ,
F_9 ( V_6 -> V_19 ) ,
F_8 ( V_6 -> V_19 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_1 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_10 , F_17 ( V_6 -> V_19 ) ,
V_25 ,
F_18 ( 31 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_5 ( V_10 , F_19 ( V_6 -> V_19 ) ,
V_26 ,
F_20 ( 1000 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned long * V_27 ,
unsigned long * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 * V_10 = V_8 -> V_11 -> V_10 ;
unsigned long V_29 ;
T_2 V_30 ;
int V_14 ;
V_29 = * V_27 + * V_28 ;
if ( V_29 > V_31 )
return - V_32 ;
if ( ! * V_27 && ! * V_28 ) {
* V_27 = 500 ;
* V_28 = 500 ;
}
V_30 = F_22 ( * V_27 , V_29 ) ;
if ( ! V_30 )
return - V_32 ;
F_23 ( & V_8 -> V_33 ) ;
if ( ! V_6 -> V_34 ) {
V_14 = F_15 ( V_2 , V_2 -> V_35 ) ;
if ( V_14 < 0 )
goto V_36;
V_6 -> V_34 = V_2 -> V_35 ;
}
V_14 = F_5 ( V_10 , F_17 ( V_6 -> V_19 ) ,
V_25 ,
F_18 ( V_30 - 1 ) ) ;
if ( V_14 < 0 )
goto V_36;
V_14 = F_5 ( V_10 , F_19 ( V_6 -> V_19 ) ,
V_26 ,
F_20 ( V_29 - 1 ) ) ;
V_36:
F_24 ( & V_8 -> V_33 ) ;
return V_14 ;
}
static int F_25 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_14 ;
F_23 ( & V_8 -> V_33 ) ;
if ( ! V_6 -> V_34 && V_4 ) {
V_14 = F_15 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
goto V_36;
} else if ( V_4 ) {
V_14 = F_1 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
goto V_36;
} else {
V_14 = F_7 ( V_2 ) ;
if ( V_14 < 0 )
goto V_36;
}
V_6 -> V_34 = V_4 ;
V_36:
F_24 ( & V_8 -> V_33 ) ;
return V_14 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
const char * V_39 ;
int V_14 = 0 ;
V_6 -> V_2 . V_40 = F_27 ( V_38 , L_1 , NULL ) ? : V_38 -> V_40 ;
V_6 -> V_2 . V_41 = F_27 ( V_38 ,
L_2 ,
NULL ) ;
V_39 = F_27 ( V_38 , L_3 , NULL ) ;
if ( V_39 ) {
if ( ! strcmp ( V_39 , L_4 ) ) {
V_14 = F_13 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_6 -> V_34 = V_14 ;
V_14 = 0 ;
} else if ( ! strcmp ( V_39 , L_5 ) ) {
V_14 =
F_25 ( V_2 , V_2 -> V_35 ) ;
} else {
V_14 = F_25 ( V_2 , V_42 ) ;
}
}
return V_14 ;
}
static int F_28 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_37 * V_38 = V_44 -> V_46 . V_47 ;
struct V_37 * V_48 ;
struct V_49 * V_11 = F_29 ( V_44 -> V_46 . V_9 ) ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
int V_14 ;
unsigned int V_20 ;
T_1 V_50 ;
V_8 = F_30 ( V_46 , sizeof( * V_8 ) , V_51 ) ;
if ( ! V_8 )
return - V_52 ;
F_31 ( V_44 , V_8 ) ;
V_8 -> V_46 = V_46 ;
V_8 -> V_11 = V_11 ;
F_32 ( & V_8 -> V_33 ) ;
V_20 = V_53 ;
V_14 = F_5 ( V_8 -> V_11 -> V_10 , V_54 ,
V_55 , ~ V_20 ) ;
if ( V_14 < 0 ) {
F_33 ( V_8 -> V_46 ,
L_6 ) ;
return V_14 ;
}
F_34 (np, child) {
V_14 = F_35 ( V_48 , L_7 , & V_50 ) ;
if ( V_14 ) {
F_33 ( V_46 , L_8 ) ;
goto V_56;
}
if ( V_50 >= V_57 || V_8 -> V_6 [ V_50 ] ) {
F_33 ( V_46 , L_9 , V_50 ) ;
V_14 = - V_32 ;
goto V_56;
}
V_6 = F_30 ( V_46 , sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 ) {
V_14 = - V_52 ;
goto V_56;
}
V_8 -> V_6 [ V_50 ] = V_6 ;
V_8 -> V_6 [ V_50 ] -> V_19 = V_50 ;
V_8 -> V_6 [ V_50 ] -> V_2 . V_35 = V_58 ;
V_8 -> V_6 [ V_50 ] -> V_2 . V_59 =
F_25 ;
V_8 -> V_6 [ V_50 ] -> V_2 . V_60 = F_21 ;
V_8 -> V_6 [ V_50 ] -> V_2 . V_61 =
F_13 ;
V_8 -> V_6 [ V_50 ] -> V_9 = V_8 ;
V_14 = F_26 ( & V_8 -> V_6 [ V_50 ] -> V_2 , V_48 ) ;
if ( V_14 < 0 ) {
F_33 ( V_8 -> V_46 ,
L_10 ) ;
goto V_56;
}
V_14 = F_36 ( V_46 , & V_8 -> V_6 [ V_50 ] -> V_2 ) ;
if ( V_14 ) {
F_33 ( & V_44 -> V_46 , L_11 ,
V_14 ) ;
goto V_56;
}
V_8 -> V_6 [ V_50 ] -> V_2 . V_46 -> V_47 = V_48 ;
}
return 0 ;
V_56:
F_37 ( V_48 ) ;
return V_14 ;
}
static int F_38 ( struct V_43 * V_44 )
{
struct V_7 * V_8 = F_39 ( V_44 ) ;
int V_62 ;
for ( V_62 = 0 ; V_8 -> V_6 [ V_62 ] ; V_62 ++ )
F_7 ( & V_8 -> V_6 [ V_62 ] -> V_2 ) ;
F_5 ( V_8 -> V_11 -> V_10 , V_54 ,
V_55 ,
V_53 ) ;
F_40 ( & V_8 -> V_33 ) ;
return 0 ;
}
