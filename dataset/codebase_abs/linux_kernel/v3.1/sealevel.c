static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
F_4 ( V_8 , V_8 -> V_9 - 2 ) ;
V_8 -> V_10 = F_5 ( V_8 , V_6 -> V_11 ) ;
F_6 ( V_8 ) ;
V_8 -> V_3 = V_6 -> V_11 ;
F_7 ( V_8 ) ;
}
static int F_8 ( struct V_2 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_12 ) ;
int V_14 = - 1 ;
int V_15 = V_13 -> V_16 ;
switch ( V_15 ) {
case 0 :
V_14 = F_9 ( V_12 , V_13 -> V_17 ) ;
break;
case 1 :
V_14 = F_10 ( V_12 , V_13 -> V_17 ) ;
break;
}
if ( V_14 )
return V_14 ;
V_14 = F_11 ( V_12 ) ;
if ( V_14 ) {
switch ( V_15 ) {
case 0 :
F_12 ( V_12 , V_13 -> V_17 ) ;
break;
case 1 :
F_13 ( V_12 , V_13 -> V_17 ) ;
break;
}
return V_14 ;
}
V_13 -> V_17 -> V_18 = F_3 ;
F_14 ( V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_12 ) ;
int V_15 = V_13 -> V_16 ;
V_13 -> V_17 -> V_18 = V_19 ;
F_16 ( V_12 ) ;
F_17 ( V_12 ) ;
switch ( V_15 ) {
case 0 :
F_12 ( V_12 , V_13 -> V_17 ) ;
break;
case 1 :
F_13 ( V_12 , V_13 -> V_17 ) ;
break;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_12 , struct V_20 * V_21 , int V_22 )
{
return F_19 ( V_12 , V_21 , V_22 ) ;
}
static T_1 F_20 ( struct V_7 * V_8 ,
struct V_2 * V_12 )
{
return F_21 ( F_1 ( V_12 ) -> V_17 , V_8 ) ;
}
static int F_22 ( struct V_2 * V_3 , unsigned short V_23 ,
unsigned short V_24 )
{
if ( V_23 == V_25 && V_24 == V_26 )
return 0 ;
return - V_27 ;
}
static int F_23 ( struct V_1 * V_28 , int V_29 , int V_30 )
{
struct V_2 * V_3 = F_24 ( V_28 ) ;
if ( ! V_3 )
return - 1 ;
F_2 ( V_3 ) -> V_31 = F_22 ;
F_2 ( V_3 ) -> V_32 = F_20 ;
V_3 -> V_33 = & V_34 ;
V_3 -> V_35 = V_29 ;
V_3 -> V_30 = V_30 ;
if ( F_25 ( V_3 ) ) {
F_26 ( L_1 ) ;
F_27 ( V_3 ) ;
return - 1 ;
}
V_28 -> V_17 -> V_11 = V_3 ;
return 0 ;
}
void T_2 F_28 ( struct V_36 * V_37 )
{
int V_38 ;
F_29 ( & V_37 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
struct V_2 * V_12 = V_37 -> V_3 [ V_38 ] . V_17 -> V_11 ;
F_30 ( V_12 ) ;
F_27 ( V_12 ) ;
}
F_31 ( V_37 -> V_39 . V_30 , & V_37 -> V_39 ) ;
F_32 ( V_37 -> V_39 . V_40 . V_41 ) ;
F_32 ( V_37 -> V_39 . V_40 . V_42 ) ;
F_33 ( 0 , V_37 -> V_29 ) ;
F_34 ( V_37 -> V_29 , 8 ) ;
F_35 ( V_37 ) ;
}
static int T_3 F_36 ( void )
{
V_43 = F_37 ( V_44 , V_30 , V_42 , V_41 , V_45 ) ;
return V_43 ? 0 : - V_46 ;
}
static void T_2 F_38 ( void )
{
if ( V_43 )
F_28 ( V_43 ) ;
}
