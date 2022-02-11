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
V_5 = F_5 ( & V_4 -> V_6 , 0 ) ;
F_6 ( V_2 -> V_7 , V_2 -> V_8 , V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_9 )
{
F_8 ( V_2 -> V_7 , V_2 -> V_8 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_7 , V_2 -> V_8 ,
V_2 -> V_10 , & V_2 -> V_11 ) ;
}
static inline unsigned int F_11 ( unsigned int V_12 , unsigned int V_13 ,
unsigned int V_14 , unsigned long V_15 )
{
unsigned int V_16 = ( V_13 + V_14 ) / 2 ;
V_15 &= V_17 | V_18 ;
if ( V_12 <= V_13 )
return V_13 ;
if ( V_12 >= V_14 )
return V_14 ;
if ( V_15 == V_17 )
return V_13 ;
if ( V_15 == V_18 )
return V_14 ;
if ( V_12 <= V_16 )
return V_13 ;
return V_14 ;
}
static inline unsigned int F_12 ( unsigned int V_19 ,
unsigned int V_20 , unsigned int V_21 , unsigned int V_15 )
{
unsigned int V_22 ;
if ( V_15 & V_23 )
return 0 ;
V_22 = V_19 - F_13 ( V_19 , V_20 / 2 ) ;
return F_13 ( V_22 , V_21 - V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_24 V_25 , unsigned long V_15 )
{
struct V_26 * V_11 = & V_2 -> V_11 ;
struct V_27 * V_28 = & V_11 -> V_28 ;
struct V_27 * V_29 = & V_11 -> V_29 ;
unsigned int V_30 , V_31 ;
switch ( V_25 ) {
case V_32 :
V_15 = 0 ;
case V_33 :
V_30 = V_29 -> V_34 + V_29 -> V_35 / 2 ;
V_31 = V_29 -> V_36 + V_29 -> V_37 / 2 ;
if ( V_15 & V_17 ) {
V_29 -> V_35 = F_15 ( V_29 -> V_35 , 2 ) ;
V_29 -> V_37 = F_15 ( V_29 -> V_37 , 2 ) ;
} else {
V_29 -> V_35 = F_16 ( V_29 -> V_35 , 2 ) ;
V_29 -> V_37 = F_16 ( V_29 -> V_37 , 2 ) ;
}
V_29 -> V_35 = F_13 ( V_29 -> V_35 , V_29 -> V_38 ) ;
V_29 -> V_37 = F_13 ( V_29 -> V_37 , V_29 -> V_39 ) ;
V_29 -> V_35 = F_13 ( V_29 -> V_35 , 2 * V_28 -> V_38 ) ;
V_29 -> V_37 = F_13 ( V_29 -> V_37 , 2 * V_28 -> V_39 ) ;
V_29 -> V_34 = F_12 ( V_30 , V_29 -> V_35 ,
V_29 -> V_38 , V_15 ) ;
V_29 -> V_36 = F_12 ( V_31 , V_29 -> V_37 ,
V_29 -> V_39 , V_15 ) ;
V_15 = 0 ;
case V_40 :
V_30 = V_28 -> V_34 + V_28 -> V_35 / 2 ;
V_31 = V_28 -> V_36 + V_28 -> V_37 / 2 ;
if ( V_28 -> V_38 < V_29 -> V_35 )
V_28 -> V_35 = V_29 -> V_35 / 2 ;
else
V_28 -> V_35 = F_11 ( V_28 -> V_35 , V_29 -> V_35 / 2 ,
V_29 -> V_35 , V_15 ) ;
if ( V_28 -> V_35 == V_29 -> V_35 )
V_11 -> V_41 = 0 ;
else
V_11 -> V_41 = 1 ;
if ( V_28 -> V_39 < V_29 -> V_37 )
V_28 -> V_37 = V_29 -> V_37 / 2 ;
else
V_28 -> V_37 = F_11 ( V_28 -> V_37 , V_29 -> V_37 / 2 ,
V_29 -> V_37 , V_15 ) ;
if ( V_28 -> V_37 == V_29 -> V_37 )
V_11 -> V_42 = 0 ;
else
V_11 -> V_42 = 1 ;
V_28 -> V_34 = F_12 ( V_30 , V_28 -> V_35 ,
V_28 -> V_38 , V_15 ) ;
V_28 -> V_36 = F_12 ( V_31 , V_28 -> V_37 ,
V_28 -> V_39 , V_15 ) ;
V_15 = 0 ;
case V_43 :
V_28 -> V_38 = F_17 ( V_28 -> V_38 ,
V_28 -> V_35 + V_28 -> V_34 , 32767 ) ;
V_28 -> V_39 = F_17 ( V_28 -> V_39 ,
V_28 -> V_37 + V_28 -> V_36 , 2047 ) ;
}
}
struct V_1 * F_18 ( struct V_44 * V_7 , int V_8 )
{
struct V_1 * V_2 ;
int V_45 ;
struct V_46 V_47 = {
. V_48 = F_1 ,
. V_49 = F_4 ,
. V_50 = F_7 ,
. V_51 = F_9 ,
. V_52 = F_14 ,
} ;
char V_53 [ 32 ] ;
sprintf ( V_53 , L_1 , V_8 ) ;
V_2 = F_19 ( V_7 , V_8 , V_53 , & V_47 ) ;
if ( V_2 == NULL ) {
F_20 ( V_7 , L_2 , V_8 ) ;
goto V_54;
}
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = F_21 ( V_56 ) ;
V_45 = F_22 ( V_2 ) ;
if ( V_45 )
goto V_58;
return V_2 ;
V_58:
F_3 ( V_2 ) ;
V_54:
return NULL ;
}
