static const struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
switch ( F_2 ( V_3 -> V_4 ) ) {
case 6 :
return & V_5 ;
case 7 :
return & V_6 ;
case 8 :
return & V_7 ;
case 9 :
return & V_8 ;
}
return NULL ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_4 )
{
const struct V_1 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_15 -> V_14 ;
unsigned int V_16 = 0 , V_17 = 0 ;
unsigned int V_18 ;
T_1 * V_19 ;
int V_20 ;
V_20 = F_4 ( V_14 , & V_18 ) ;
if ( V_20 )
return V_20 ;
V_19 = F_5 ( F_6 ( V_14 , 0 ) ) ;
while ( V_16 < V_12 -> V_21 ) {
T_1 V_22 = V_12 -> V_23 [ V_16 ] ;
if ( V_16 * 4 == V_12 -> V_24 [ V_17 ] ) {
T_2 V_25 = V_22 + V_10 -> V_15 -> V_26 . V_27 ;
V_22 = F_7 ( V_25 ) ;
if ( F_8 ( V_4 ) ) {
if ( V_16 + 1 >= V_12 -> V_21 ||
V_12 -> V_23 [ V_16 + 1 ] != 0 )
goto V_28;
V_19 [ V_16 ++ ] = V_22 ;
V_22 = F_9 ( V_25 ) ;
}
V_17 ++ ;
}
V_19 [ V_16 ++ ] = V_22 ;
}
if ( V_12 -> V_24 [ V_17 ] != - 1 ) {
F_10 ( L_1 , V_17 ) ;
goto V_28;
}
V_10 -> V_29 = V_10 -> V_15 -> V_26 . V_27 ;
V_10 -> V_30 = V_12 -> V_21 * sizeof( T_1 ) ;
while ( V_16 % V_31 )
F_11 ( V_19 , V_16 , V_32 ) ;
V_10 -> V_33 = V_16 * sizeof( T_1 ) ;
if ( F_12 ( V_4 ) ) {
T_1 V_34 = 0x00777000 ;
F_11 ( V_19 , V_16 , V_35 ) ;
F_11 ( V_19 , V_16 , V_36 ) ;
F_11 ( V_19 , V_16 , V_34 ) ;
F_11 ( V_19 , V_16 , 0 ) ;
F_11 ( V_19 , V_16 , 0 ) ;
F_11 ( V_19 , V_16 , 0 ) ;
}
F_11 ( V_19 , V_16 , V_37 ) ;
V_10 -> V_38 = V_16 * sizeof( T_1 ) - V_10 -> V_33 ;
V_10 -> V_33 += V_10 -> V_29 ;
V_10 -> V_38 = F_13 ( V_10 -> V_38 , 8 ) ;
if ( V_18 )
F_14 ( V_19 , V_16 * sizeof( T_1 ) ) ;
F_15 ( V_19 ) ;
V_20 = F_16 ( V_14 , false ) ;
V_39:
F_17 ( V_14 ) ;
return V_20 ;
V_28:
F_15 ( V_19 ) ;
V_20 = - V_40 ;
goto V_39;
}
int F_18 ( struct V_2 * V_3 )
{
struct V_9 * V_10 ;
const struct V_1 * V_12 ;
struct V_13 * V_14 ;
int V_20 ;
if ( V_3 -> V_41 != V_42 )
return 0 ;
V_12 = F_1 ( V_3 ) ;
if ( ! V_12 )
return 0 ;
if ( V_12 -> V_21 * 4 > V_43 )
return - V_40 ;
V_10 = F_19 ( sizeof( * V_10 ) , V_44 ) ;
if ( ! V_10 )
return - V_45 ;
V_14 = F_20 ( V_3 -> V_4 , V_43 ) ;
if ( F_21 ( V_14 ) ) {
V_20 = F_22 ( V_14 ) ;
goto V_46;
}
V_10 -> V_15 = F_23 ( V_14 , & V_3 -> V_4 -> V_47 . V_48 , NULL ) ;
if ( F_21 ( V_10 -> V_15 ) ) {
V_20 = F_22 ( V_10 -> V_15 ) ;
goto V_49;
}
V_10 -> V_12 = V_12 ;
V_3 -> V_50 = V_10 ;
return 0 ;
V_49:
F_24 ( V_14 ) ;
V_46:
F_25 ( V_10 ) ;
return V_20 ;
}
int F_26 ( struct V_51 * V_52 )
{
struct V_9 * V_10 ;
int V_20 ;
F_27 ( & V_52 -> V_4 -> V_53 . V_54 ) ;
V_10 = V_52 -> V_3 -> V_50 ;
if ( ! V_10 )
return 0 ;
if ( ! V_10 -> V_15 -> V_14 -> V_55 . V_56 )
V_10 -> V_29 = - 1 ;
V_20 = F_28 ( V_10 -> V_15 , 0 , 0 , V_57 | V_58 ) ;
if ( V_20 )
return V_20 ;
if ( V_10 -> V_15 -> V_26 . V_27 != V_10 -> V_29 ) {
V_20 = F_3 ( V_10 , V_52 -> V_4 ) ;
if ( V_20 )
goto V_59;
}
V_20 = V_52 -> V_3 -> V_60 ( V_52 , V_61 ) ;
if ( V_20 )
goto V_59;
V_20 = V_52 -> V_3 -> V_62 ( V_52 ,
V_10 -> V_29 , V_10 -> V_30 ,
V_63 ) ;
if ( V_20 )
goto V_59;
if ( V_10 -> V_38 > 8 ) {
V_20 = V_52 -> V_3 -> V_62 ( V_52 ,
V_10 -> V_33 , V_10 -> V_38 ,
V_63 ) ;
if ( V_20 )
goto V_59;
}
F_29 ( V_10 -> V_15 , V_52 , 0 ) ;
V_59:
F_30 ( V_10 -> V_15 ) ;
return V_20 ;
}
void F_31 ( struct V_2 * V_3 )
{
struct V_9 * V_10 ;
struct V_13 * V_14 ;
V_10 = F_32 ( & V_3 -> V_50 ) ;
if ( ! V_10 )
return;
V_14 = V_10 -> V_15 -> V_14 ;
F_33 ( V_10 -> V_15 ) ;
F_34 ( V_14 ) ;
F_25 ( V_10 ) ;
}
