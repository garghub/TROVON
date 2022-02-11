static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long long V_4 , div ;
int V_5 = 0 ;
T_1 V_6 , V_7 ;
div = ( unsigned long long ) F_2 ( V_2 -> V_8 ) ;
F_3 ( div , V_3 ) ;
V_4 = div ;
while ( div > V_2 -> V_9 ) {
V_5 ++ ;
div = V_4 ;
F_3 ( div , ( V_5 + 1 ) ) ;
}
V_4 = div ;
if ( V_5 > V_10 ) {
F_4 ( V_2 -> V_11 , L_1 ) ;
return - V_12 ;
}
F_5 ( V_2 -> V_13 , V_14 , & V_6 ) ;
if ( V_6 & V_15 )
return - V_16 ;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
if ( ! ( V_7 & V_18 ) )
F_6 ( V_2 -> V_8 ) ;
F_7 ( V_2 -> V_13 , V_19 , V_5 ) ;
F_7 ( V_2 -> V_13 , V_20 , V_4 - 1 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_21 , V_21 ) ;
F_8 ( V_2 -> V_13 , V_22 , V_23 , 0x20 ) ;
F_8 ( V_2 -> V_13 , V_24 , V_25 , V_25 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_18 , V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 ;
F_5 ( V_2 -> V_13 , V_14 , & V_6 ) ;
if ( V_6 & V_15 )
return;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
if ( V_7 & V_18 )
F_10 ( V_2 -> V_8 ) ;
F_8 ( V_2 -> V_13 , V_17 , V_18 , 0 ) ;
F_7 ( V_2 -> V_13 , V_19 , 0 ) ;
F_7 ( V_2 -> V_13 , V_20 , 0 ) ;
F_8 ( V_2 -> V_13 , V_24 , V_25 , V_25 ) ;
}
static T_2 F_11 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_30 )
{
struct V_31 * V_32 = F_12 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_32 ) ;
unsigned int V_33 ;
int V_34 ;
V_34 = F_14 ( V_29 , 10 , & V_33 ) ;
if ( V_34 )
return V_34 ;
if ( V_33 == 0 ) {
F_9 ( V_2 ) ;
} else {
V_34 = F_1 ( V_2 , V_33 ) ;
if ( V_34 )
return V_34 ;
}
return V_30 ;
}
static T_2 F_15 ( struct V_26 * V_11 ,
struct V_27 * V_28 , char * V_29 )
{
struct V_31 * V_32 = F_12 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_32 ) ;
T_1 V_35 , V_36 , V_7 ;
unsigned long long V_33 = 0 ;
F_5 ( V_2 -> V_13 , V_17 , & V_7 ) ;
F_5 ( V_2 -> V_13 , V_19 , & V_35 ) ;
F_5 ( V_2 -> V_13 , V_20 , & V_36 ) ;
if ( V_35 && V_36 && ( V_7 & V_18 ) ) {
V_33 = ( unsigned long long ) F_2 ( V_2 -> V_8 ) ;
F_3 ( V_33 , V_35 ) ;
F_3 ( V_33 , V_36 ) ;
}
return sprintf ( V_29 , L_2 , ( unsigned int ) V_33 ) ;
}
static T_2 F_16 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_37 * V_38 = F_17 ( V_11 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
T_1 V_39 ;
F_5 ( V_2 -> V_13 , V_22 , & V_39 ) ;
V_39 = ( V_39 & V_23 ) >> V_40 ;
return snprintf ( V_29 , V_41 , L_3 , V_42 [ V_39 ] ) ;
}
static T_2 F_19 ( struct V_26 * V_11 ,
struct V_27 * V_28 ,
const char * V_29 , T_3 V_30 )
{
struct V_37 * V_38 = F_17 ( V_11 ) ;
struct V_1 * V_2 = F_18 ( V_38 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_20 ( V_42 ) ; V_43 ++ ) {
if ( ! strncmp ( V_42 [ V_43 ] , V_29 ,
strlen ( V_42 [ V_43 ] ) ) ) {
F_8 ( V_2 -> V_13 , V_22 ,
V_23 , V_43 << V_40 ) ;
F_8 ( V_2 -> V_13 , V_24 ,
V_25 , V_25 ) ;
return V_30 ;
}
}
return - V_12 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_34 ;
const char * const * V_44 = V_2 -> V_45 ;
while ( V_44 && * V_44 ) {
struct V_31 * V_32 ;
V_32 = F_22 ( V_2 -> V_11 , L_4 , * V_44 ) ;
if ( ! V_32 )
return - V_46 ;
V_32 -> V_11 . V_47 = V_2 -> V_11 -> V_47 ;
V_32 -> V_48 = & V_49 ;
if ( V_44 == V_2 -> V_45 )
V_32 -> V_11 . V_50 = V_51 ;
F_23 ( V_32 , V_2 ) ;
V_34 = F_24 ( V_2 -> V_11 , V_32 ) ;
if ( V_34 )
return V_34 ;
V_44 ++ ;
}
return 0 ;
}
bool F_25 ( struct V_31 * V_32 )
{
return ( V_32 -> V_48 == & V_49 ) ;
}
static int F_26 ( struct V_52 * V_53 )
{
struct V_26 * V_11 = & V_53 -> V_11 ;
struct V_1 * V_2 ;
struct V_54 * V_55 = F_27 ( V_53 -> V_11 . V_47 ) ;
unsigned int V_56 ;
int V_34 ;
if ( F_28 ( V_11 -> V_57 , L_5 , & V_56 ) )
return - V_12 ;
if ( V_56 >= F_20 ( V_58 ) )
return - V_12 ;
V_2 = F_29 ( V_11 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_13 = V_55 -> V_13 ;
V_2 -> V_8 = V_55 -> V_8 ;
V_2 -> V_9 = V_55 -> V_9 ;
V_2 -> V_45 = V_58 [ V_56 ] ;
V_34 = F_21 ( V_2 ) ;
if ( V_34 )
return V_34 ;
F_30 ( V_53 , V_2 ) ;
return 0 ;
}
