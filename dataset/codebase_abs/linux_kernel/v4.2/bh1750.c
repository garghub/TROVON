static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
T_2 V_6 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
if ( ( V_3 % V_8 -> V_9 ) != 0 )
return - V_10 ;
V_5 = V_3 / V_8 -> V_9 ;
if ( V_5 < V_8 -> V_11 || V_5 > V_8 -> V_12 )
return - V_10 ;
V_4 = F_2 ( V_2 -> V_13 , V_14 ) ;
if ( V_4 < 0 )
return V_4 ;
V_6 = ( V_5 & V_8 -> V_15 ) >> 5 ;
V_4 = F_2 ( V_2 -> V_13 ,
V_16 | V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_6 = V_5 & V_8 -> V_17 ;
V_4 = F_2 ( V_2 -> V_13 ,
V_18 | V_6 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_19 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_5 )
{
int V_4 ;
T_3 V_20 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_21 = V_8 -> V_9 * V_2 -> V_19 ;
V_4 = F_2 ( V_2 -> V_13 , V_22 ) ;
if ( V_4 < 0 )
return V_4 ;
F_4 ( V_21 + 15000 , V_21 + 40000 ) ;
V_4 = F_5 ( V_2 -> V_13 , ( char * ) & V_20 , 2 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_5 = F_6 ( V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int * V_5 , int * V_27 , long V_28 )
{
int V_4 , V_29 ;
struct V_1 * V_2 = F_8 ( V_24 ) ;
const struct V_7 * V_8 = V_2 -> V_8 ;
switch ( V_28 ) {
case V_30 :
switch ( V_26 -> type ) {
case V_31 :
F_9 ( & V_2 -> V_32 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
F_10 ( & V_2 -> V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_33 ;
default:
return - V_10 ;
}
case V_34 :
V_29 = V_8 -> V_35 / V_2 -> V_19 ;
* V_5 = V_29 / 1000000 ;
* V_27 = V_29 % 1000000 ;
return V_36 ;
case V_37 :
* V_5 = 0 ;
* V_27 = V_8 -> V_9 * V_2 -> V_19 ;
return V_36 ;
default:
return - V_10 ;
}
}
static int F_11 ( struct V_23 * V_24 ,
struct V_25 const * V_26 ,
int V_5 , int V_27 , long V_28 )
{
int V_4 ;
struct V_1 * V_2 = F_8 ( V_24 ) ;
switch ( V_28 ) {
case V_37 :
if ( V_5 != 0 )
return - V_10 ;
F_9 ( & V_2 -> V_32 ) ;
V_4 = F_1 ( V_2 , V_27 ) ;
F_10 ( & V_2 -> V_32 ) ;
return V_4 ;
default:
return - V_10 ;
}
}
static T_4 F_12 ( struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_42 )
{
int V_43 ;
T_5 V_44 = 0 ;
struct V_1 * V_2 = F_8 ( F_13 ( V_39 ) ) ;
const struct V_7 * V_8 = V_2 -> V_8 ;
for ( V_43 = V_8 -> V_11 ; V_43 <= V_8 -> V_12 ; V_43 += V_8 -> V_45 )
V_44 += F_14 ( V_42 + V_44 , V_46 - V_44 , L_1 ,
V_8 -> V_9 * V_43 ) ;
V_42 [ V_44 - 1 ] = '\n' ;
return V_44 ;
}
static int F_15 ( struct V_47 * V_13 ,
const struct V_48 * V_49 )
{
int V_4 , V_3 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
if ( ! F_16 ( V_13 -> V_50 , V_51 |
V_52 ) )
return - V_53 ;
V_24 = F_17 ( & V_13 -> V_39 , sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_54 ;
V_2 = F_8 ( V_24 ) ;
F_18 ( V_13 , V_24 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_8 = & V_55 [ V_49 -> V_56 ] ;
V_3 = V_2 -> V_8 -> V_9 * V_2 -> V_8 -> V_57 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_19 ( & V_2 -> V_32 ) ;
V_24 -> V_39 . V_58 = & V_13 -> V_39 ;
V_24 -> V_59 = & V_60 ;
V_24 -> V_61 = V_49 -> V_61 ;
V_24 -> V_62 = V_63 ;
V_24 -> V_64 = F_20 ( V_63 ) ;
V_24 -> V_65 = V_66 ;
return F_21 ( V_24 ) ;
}
static int F_22 ( struct V_47 * V_13 )
{
struct V_23 * V_24 = F_23 ( V_13 ) ;
struct V_1 * V_2 = F_8 ( V_24 ) ;
F_24 ( V_24 ) ;
F_9 ( & V_2 -> V_32 ) ;
F_2 ( V_13 , V_14 ) ;
F_10 ( & V_2 -> V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_39 )
{
int V_4 ;
struct V_1 * V_2 =
F_8 ( F_23 ( F_26 ( V_39 ) ) ) ;
F_9 ( & V_2 -> V_32 ) ;
V_4 = F_2 ( V_2 -> V_13 , V_14 ) ;
F_10 ( & V_2 -> V_32 ) ;
return V_4 ;
}
