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
struct V_3 * V_4 = F_6 ( V_22 ,
struct V_3 , V_8 . V_22 . V_22 ) ;
unsigned int V_1 = V_4 -> V_8 . V_1 ;
int V_23 = F_7 ( V_11 . V_24 ) ;
F_8 ( & V_4 -> V_8 . V_25 ) ;
F_9 ( & V_26 , V_1 ) ;
F_10 ( V_1 , & V_4 -> V_8 . V_22 , V_23 ) ;
F_11 ( & V_4 -> V_8 . V_25 ) ;
}
static int F_12 ( struct V_27 * V_28 , unsigned long V_29 ,
void * V_30 )
{
struct V_31 * V_32 = V_30 ;
struct V_3 * V_4 =
& F_2 ( V_5 , V_32 -> V_1 ) ;
struct V_6 * V_7 ;
if ( ! V_4 -> V_33 )
return 0 ;
V_7 = V_4 -> V_8 . V_9 ;
if ( V_4 -> V_15 > V_7 -> V_16
|| V_4 -> V_15 < V_7 -> V_19 )
V_4 -> V_15 = V_32 -> V_34 ;
return 0 ;
}
static T_1 F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 , char * V_39 )
{
return sprintf ( V_39 , L_1 , V_26 . V_40 ) ;
}
static T_1 F_14 ( struct V_35 * V_41 ,
struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 || V_44 > V_46 || V_44 < 1 )
return - V_47 ;
V_11 . V_48 = V_44 ;
return V_43 ;
}
static T_1 F_15 ( struct V_35 * V_41 , struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_47 ;
V_11 . V_24 = V_16 ( V_44 , V_26 . V_40 ) ;
return V_43 ;
}
static T_1 F_16 ( struct V_35 * V_41 , struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 || V_44 > 100 || V_44 <= V_11 . V_18 )
return - V_47 ;
V_11 . V_13 = V_44 ;
return V_43 ;
}
static T_1 F_17 ( struct V_35 * V_41 , struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 || V_44 < 11 || V_44 > 100 ||
V_44 >= V_11 . V_13 )
return - V_47 ;
V_11 . V_18 = V_44 ;
return V_43 ;
}
static T_1 F_18 ( struct V_35 * V_41 , struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 , V_49 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_47 ;
if ( V_44 > 1 )
V_44 = 1 ;
if ( V_44 == V_11 . V_50 )
return V_43 ;
V_11 . V_50 = V_44 ;
F_19 (j) {
struct V_3 * V_4 ;
V_4 = & F_2 ( V_5 , V_49 ) ;
V_4 -> V_8 . V_51 = F_20 ( V_49 ,
& V_4 -> V_8 . V_52 ) ;
if ( V_11 . V_50 )
V_4 -> V_8 . V_53 =
F_21 ( V_49 ) . V_54 [ V_55 ] ;
}
return V_43 ;
}
static T_1 F_22 ( struct V_35 * V_41 , struct V_37 * V_42 ,
const char * V_39 , T_2 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_39 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_47 ;
if ( V_44 > 100 )
V_44 = 100 ;
V_11 . V_12 = V_44 ;
return V_43 ;
}
static int F_23 ( struct V_6 * V_7 ,
unsigned int V_56 )
{
return F_24 ( & V_26 , V_7 , V_56 ) ;
}
static int T_3 F_25 ( void )
{
F_26 ( & V_26 . V_57 ) ;
return F_27 ( & V_58 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_58 ) ;
}
