static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( V_4 )
V_5 = F_5 ( & V_4 -> V_6 . V_7 , 0 ) ;
F_6 ( V_2 -> V_8 , V_2 -> V_9 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
F_8 ( V_2 -> V_8 , V_2 -> V_9 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_8 , V_2 -> V_9 ,
V_2 -> V_11 , & V_2 -> V_12 ) ;
}
static inline unsigned int F_11 ( unsigned int V_13 , unsigned int V_14 ,
unsigned int V_15 , unsigned long V_16 )
{
unsigned int V_17 = ( V_14 + V_15 ) / 2 ;
V_16 &= V_18 | V_19 ;
if ( V_13 <= V_14 )
return V_14 ;
if ( V_13 >= V_15 )
return V_15 ;
if ( V_16 == V_18 )
return V_14 ;
if ( V_16 == V_19 )
return V_15 ;
if ( V_13 <= V_17 )
return V_14 ;
return V_15 ;
}
static inline unsigned int F_12 ( unsigned int V_20 ,
unsigned int V_21 , unsigned int V_22 , unsigned int V_16 )
{
unsigned int V_23 ;
if ( V_16 & V_24 )
return 0 ;
V_23 = V_20 - F_13 ( V_20 , V_21 / 2 ) ;
return F_13 ( V_23 , V_22 - V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_25 V_26 , unsigned long V_16 )
{
struct V_27 * V_12 = & V_2 -> V_12 ;
struct V_28 * V_29 = & V_12 -> V_29 ;
struct V_28 * V_30 = & V_12 -> V_30 ;
unsigned int V_31 , V_32 ;
switch ( V_26 ) {
case V_33 :
V_16 = 0 ;
case V_34 :
V_31 = V_30 -> V_35 + V_30 -> V_36 / 2 ;
V_32 = V_30 -> V_37 + V_30 -> V_38 / 2 ;
if ( V_16 & V_18 ) {
V_30 -> V_36 = F_15 ( V_30 -> V_36 , 2 ) ;
V_30 -> V_38 = F_15 ( V_30 -> V_38 , 2 ) ;
} else {
V_30 -> V_36 = F_16 ( V_30 -> V_36 , 2 ) ;
V_30 -> V_38 = F_16 ( V_30 -> V_38 , 2 ) ;
}
V_30 -> V_36 = F_13 ( V_30 -> V_36 , V_30 -> V_39 ) ;
V_30 -> V_38 = F_13 ( V_30 -> V_38 , V_30 -> V_40 ) ;
V_30 -> V_36 = F_13 ( V_30 -> V_36 , 2 * V_29 -> V_39 ) ;
V_30 -> V_38 = F_13 ( V_30 -> V_38 , 2 * V_29 -> V_40 ) ;
V_30 -> V_35 = F_12 ( V_31 , V_30 -> V_36 ,
V_30 -> V_39 , V_16 ) ;
V_30 -> V_37 = F_12 ( V_32 , V_30 -> V_38 ,
V_30 -> V_40 , V_16 ) ;
V_16 = 0 ;
case V_41 :
V_31 = V_29 -> V_35 + V_29 -> V_36 / 2 ;
V_32 = V_29 -> V_37 + V_29 -> V_38 / 2 ;
if ( V_29 -> V_39 < V_30 -> V_36 )
V_29 -> V_36 = V_30 -> V_36 / 2 ;
else
V_29 -> V_36 = F_11 ( V_29 -> V_36 , V_30 -> V_36 / 2 ,
V_30 -> V_36 , V_16 ) ;
if ( V_29 -> V_36 == V_30 -> V_36 )
V_12 -> V_42 = 0 ;
else
V_12 -> V_42 = 1 ;
if ( V_29 -> V_40 < V_30 -> V_38 )
V_29 -> V_38 = V_30 -> V_38 / 2 ;
else
V_29 -> V_38 = F_11 ( V_29 -> V_38 , V_30 -> V_38 / 2 ,
V_30 -> V_38 , V_16 ) ;
if ( V_29 -> V_38 == V_30 -> V_38 )
V_12 -> V_43 = 0 ;
else
V_12 -> V_43 = 1 ;
V_29 -> V_35 = F_12 ( V_31 , V_29 -> V_36 ,
V_29 -> V_39 , V_16 ) ;
V_29 -> V_37 = F_12 ( V_32 , V_29 -> V_38 ,
V_29 -> V_40 , V_16 ) ;
V_16 = 0 ;
case V_44 :
V_29 -> V_39 = F_17 ( V_29 -> V_39 ,
V_29 -> V_36 + V_29 -> V_35 , 32767 ) ;
V_29 -> V_40 = F_17 ( V_29 -> V_40 ,
V_29 -> V_38 + V_29 -> V_37 , 2047 ) ;
}
}
struct V_1 * F_18 ( struct V_45 * V_8 , int V_9 )
{
struct V_1 * V_2 ;
int V_46 ;
struct V_47 V_48 = {
. V_49 = F_1 ,
. V_50 = F_4 ,
. V_51 = F_7 ,
. V_52 = F_9 ,
. V_53 = F_14 ,
} ;
char V_54 [ 32 ] ;
sprintf ( V_54 , L_1 , V_9 ) ;
V_2 = F_19 ( V_8 , V_9 , V_54 , & V_48 ) ;
if ( V_2 == NULL ) {
F_20 ( V_8 , L_2 , V_9 ) ;
goto V_55;
}
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = F_21 ( V_57 ) ;
V_46 = F_22 ( V_2 ) ;
if ( V_46 )
goto V_59;
return V_2 ;
V_59:
F_3 ( V_2 ) ;
V_55:
return NULL ;
}
