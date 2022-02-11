static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( L_1 ,
V_6 , V_4 -> V_7 , V_4 -> V_8 ) ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_6 ( V_4 -> V_10 , V_11 ,
V_14 | V_15 |
V_16 | V_17 ,
F_7 ( V_4 -> V_8 ) |
V_16 |
F_8 ( V_4 -> V_7 ) |
V_17 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_6 ( V_4 -> V_10 , V_11 ,
V_16 | V_17 ,
V_16 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
unsigned int V_18 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_12 ( V_4 -> V_10 , V_11 , & V_18 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
return V_18 & V_17 ? 1 : 0 ;
}
static unsigned long
F_13 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_14 ( V_19 , V_4 -> V_7 + 1 ) ;
}
static void F_15 ( struct V_20 * V_21 ,
struct V_1 * V_22 ,
unsigned long V_19 , T_1 div ,
int * V_23 , long * V_24 )
{
unsigned long V_25 ;
int V_26 ;
if ( ! div )
V_25 = V_19 ;
else
V_25 = V_19 / div ;
V_26 = abs ( V_21 -> V_27 - V_25 ) ;
if ( * V_23 < 0 || * V_23 > V_26 ) {
* V_24 = V_25 ;
* V_23 = V_26 ;
V_21 -> V_28 = V_19 ;
V_21 -> V_29 = V_22 ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_22 = NULL ;
struct V_20 V_30 = * V_21 ;
long V_24 = - V_31 ;
unsigned long V_32 , V_19 ;
int V_23 = - 1 ;
int V_33 ;
T_1 div ;
for ( V_33 = 0 ; V_33 < F_17 ( V_2 ) - 1 ; V_33 ++ ) {
V_22 = F_18 ( V_2 , V_33 ) ;
if ( ! V_22 )
continue;
V_19 = F_19 ( V_22 ) ;
V_32 = F_14 ( V_19 , V_34 + 1 ) ;
if ( ! V_19 ||
( V_4 -> V_35 . V_36 && V_32 > V_4 -> V_35 . V_36 ) )
continue;
div = F_14 ( V_19 , V_21 -> V_27 ) ;
F_15 ( V_21 , V_22 , V_19 , div ,
& V_23 , & V_24 ) ;
if ( ! V_23 )
break;
}
if ( ! V_4 -> V_37 )
goto V_38;
V_22 = F_18 ( V_2 , V_39 ) ;
if ( ! V_22 )
goto V_38;
for ( div = 1 ; div < V_34 + 2 ; div ++ ) {
V_30 . V_27 = V_21 -> V_27 * div ;
F_20 ( V_22 , & V_30 ) ;
F_15 ( V_21 , V_22 , V_30 . V_27 , div ,
& V_23 , & V_24 ) ;
if ( ! V_23 )
break;
}
V_38:
F_3 ( L_2 ,
V_6 , V_24 ,
F_21 ( ( V_21 -> V_29 ) -> V_40 ) ,
V_21 -> V_28 ) ;
if ( V_24 < 0 )
return V_24 ;
V_21 -> V_27 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_41 >= F_17 ( V_2 ) )
return - V_31 ;
V_4 -> V_8 = V_41 ;
return 0 ;
}
static T_2 F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_8 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned long V_27 ,
unsigned long V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div ;
if ( ! V_27 )
return - V_31 ;
if ( V_4 -> V_35 . V_36 && V_27 > V_4 -> V_35 . V_36 )
return - V_31 ;
div = F_14 ( V_19 , V_27 ) ;
if ( div > V_34 + 1 || ! div )
return - V_31 ;
V_4 -> V_7 = div - 1 ;
return 0 ;
}
static void F_25 ( struct V_3 * V_4 )
{
T_1 V_42 ;
unsigned long V_5 ;
F_4 ( V_4 -> V_9 , V_5 ) ;
F_5 ( V_4 -> V_10 , V_11 ,
( V_4 -> V_12 & V_13 ) ) ;
F_12 ( V_4 -> V_10 , V_11 , & V_42 ) ;
F_9 ( V_4 -> V_9 , V_5 ) ;
V_4 -> V_8 = ( V_42 & V_15 )
>> V_43 ;
V_4 -> V_7 = ( V_42 & V_14 )
>> V_44 ;
}
static struct V_1 * T_3
F_26 ( struct V_10 * V_10 , T_4 * V_9 ,
const char * V_45 , const char * * V_46 ,
T_2 V_47 , T_2 V_12 ,
const struct V_48 * V_35 )
{
struct V_3 * V_4 ;
struct V_49 V_50 ;
struct V_1 * V_2 ;
int V_51 ;
V_4 = F_27 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return F_28 ( - V_53 ) ;
V_50 . V_45 = V_45 ;
V_50 . V_54 = & V_55 ;
V_50 . V_46 = V_46 ;
V_50 . V_47 = V_47 ;
V_50 . V_5 = V_56 | V_57 |
V_58 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_2 . V_50 = & V_50 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_35 = * V_35 ;
F_25 ( V_4 ) ;
V_2 = & V_4 -> V_2 ;
V_51 = F_29 ( NULL , & V_4 -> V_2 ) ;
if ( V_51 ) {
F_30 ( V_4 ) ;
V_2 = F_28 ( V_51 ) ;
} else {
F_31 ( V_12 ) ;
}
return V_2 ;
}
static void T_3 F_32 ( struct V_59 * V_60 )
{
int V_61 ;
T_1 V_12 ;
const char * V_45 ;
struct V_1 * V_2 ;
unsigned int V_47 ;
const char * V_46 [ V_62 ] ;
struct V_59 * V_63 ;
struct V_48 V_35 = F_33 ( 0 , 0 ) ;
struct V_10 * V_10 ;
struct V_3 * V_4 ;
V_47 = F_34 ( V_60 ) ;
if ( V_47 == 0 || V_47 > V_62 )
return;
F_35 ( V_60 , V_46 , V_47 ) ;
V_61 = F_36 ( V_60 ) ;
if ( ! V_61 || V_61 > V_64 )
return;
V_10 = F_37 ( F_38 ( V_60 ) ) ;
if ( F_39 ( V_10 ) )
return;
F_40 (np, gcknp) {
if ( F_41 ( V_63 , L_3 , & V_12 ) )
continue;
if ( V_12 < V_65 || V_12 >= V_64 )
continue;
if ( F_42 ( V_60 , L_4 , & V_45 ) )
V_45 = V_63 -> V_45 ;
F_43 ( V_63 , L_5 ,
& V_35 ) ;
V_2 = F_26 ( V_10 , & V_66 , V_45 ,
V_46 , V_47 ,
V_12 , & V_35 ) ;
V_4 = F_2 ( V_2 ) ;
if ( F_44 ( V_60 ,
L_6 ) ) {
if ( V_4 -> V_12 == V_67 || V_4 -> V_12 == V_68 ||
V_4 -> V_12 == V_69 || V_4 -> V_12 == V_70 ||
V_4 -> V_12 == V_71 )
V_4 -> V_37 = true ;
else
V_4 -> V_37 = false ;
} else {
V_4 -> V_37 = false ;
}
if ( F_39 ( V_2 ) )
continue;
F_45 ( V_63 , V_72 , V_2 ) ;
}
}
