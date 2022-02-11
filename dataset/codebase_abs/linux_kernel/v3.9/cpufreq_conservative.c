static void F_1 ( int V_1 , unsigned int V_2 )
{
struct V_3 * V_4 = & F_2 ( V_5 , V_1 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_9 ;
unsigned int V_10 ;
if ( V_11 . V_12 == 0 )
return;
if ( V_2 > V_11 . V_13 ) {
V_4 -> V_14 = 0 ;
if ( V_4 -> V_15 == V_7 -> V_16 )
return;
V_10 = ( V_11 . V_12 * V_7 -> V_16 ) / 100 ;
if ( F_3 ( V_10 == 0 ) )
V_10 = 5 ;
V_4 -> V_15 += V_10 ;
if ( V_4 -> V_15 > V_7 -> V_16 )
V_4 -> V_15 = V_7 -> V_16 ;
F_4 ( V_7 , V_4 -> V_15 ,
V_17 ) ;
return;
}
if ( V_2 < ( V_11 . V_18 - 10 ) ) {
V_10 = ( V_11 . V_12 * V_7 -> V_16 ) / 100 ;
V_4 -> V_15 -= V_10 ;
if ( V_4 -> V_15 < V_7 -> V_19 )
V_4 -> V_15 = V_7 -> V_19 ;
if ( V_7 -> V_20 == V_7 -> V_19 )
return;
F_4 ( V_7 , V_4 -> V_15 ,
V_17 ) ;
return;
}
}
static void F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_6 ( V_22 ) ;
struct V_3 * V_4 = F_7 ( V_22 ,
struct V_3 , V_8 . V_22 . V_22 ) ;
unsigned int V_1 = V_4 -> V_8 . V_9 -> V_1 ;
struct V_3 * V_25 = & F_2 ( V_5 ,
V_1 ) ;
int V_26 = F_8 ( V_11 . V_27 ) ;
F_9 ( & V_25 -> V_8 . V_28 ) ;
if ( F_10 ( & V_25 -> V_8 , V_11 . V_27 ) )
F_11 ( & V_29 , V_1 ) ;
F_12 ( F_13 () , V_24 , V_26 ) ;
F_14 ( & V_25 -> V_8 . V_28 ) ;
}
static int F_15 ( struct V_30 * V_31 , unsigned long V_32 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_3 * V_4 =
& F_2 ( V_5 , V_35 -> V_1 ) ;
struct V_6 * V_7 ;
if ( ! V_4 -> V_36 )
return 0 ;
V_7 = V_4 -> V_8 . V_9 ;
if ( V_4 -> V_15 > V_7 -> V_16
|| V_4 -> V_15 < V_7 -> V_19 )
V_4 -> V_15 = V_35 -> V_37 ;
return 0 ;
}
static T_1 F_16 ( struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_42 )
{
return sprintf ( V_42 , L_1 , V_29 . V_43 ) ;
}
static T_1 F_17 ( struct V_38 * V_44 ,
struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 || V_47 > V_49 || V_47 < 1 )
return - V_50 ;
V_11 . V_51 = V_47 ;
return V_46 ;
}
static T_1 F_18 ( struct V_38 * V_44 , struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 )
return - V_50 ;
V_11 . V_27 = V_16 ( V_47 , V_29 . V_43 ) ;
return V_46 ;
}
static T_1 F_19 ( struct V_38 * V_44 , struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 || V_47 > 100 || V_47 <= V_11 . V_18 )
return - V_50 ;
V_11 . V_13 = V_47 ;
return V_46 ;
}
static T_1 F_20 ( struct V_38 * V_44 , struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 || V_47 < 11 || V_47 > 100 ||
V_47 >= V_11 . V_13 )
return - V_50 ;
V_11 . V_18 = V_47 ;
return V_46 ;
}
static T_1 F_21 ( struct V_38 * V_44 , struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 , V_52 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 )
return - V_50 ;
if ( V_47 > 1 )
V_47 = 1 ;
if ( V_47 == V_11 . V_53 )
return V_46 ;
V_11 . V_53 = V_47 ;
F_22 (j) {
struct V_3 * V_4 ;
V_4 = & F_2 ( V_5 , V_52 ) ;
V_4 -> V_8 . V_54 = F_23 ( V_52 ,
& V_4 -> V_8 . V_55 ) ;
if ( V_11 . V_53 )
V_4 -> V_8 . V_56 =
F_24 ( V_52 ) . V_57 [ V_58 ] ;
}
return V_46 ;
}
static T_1 F_25 ( struct V_38 * V_44 , struct V_40 * V_45 ,
const char * V_42 , T_2 V_46 )
{
unsigned int V_47 ;
int V_48 ;
V_48 = sscanf ( V_42 , L_2 , & V_47 ) ;
if ( V_48 != 1 )
return - V_50 ;
if ( V_47 > 100 )
V_47 = 100 ;
V_11 . V_12 = V_47 ;
return V_46 ;
}
static int F_26 ( struct V_6 * V_7 ,
unsigned int V_59 )
{
return F_27 ( & V_29 , V_7 , V_59 ) ;
}
static int T_3 F_28 ( void )
{
F_29 ( & V_29 . V_60 ) ;
return F_30 ( & V_61 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_61 ) ;
}
