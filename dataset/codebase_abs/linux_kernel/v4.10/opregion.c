static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 = V_2 -> V_5 -> V_6 . V_7 ;
T_3 * V_8 ;
int V_9 ;
if ( F_2 ( ( F_3 ( V_2 ) -> V_10 ) ,
L_1 ,
V_2 -> V_11 ) )
return - V_12 ;
F_3 ( V_2 ) -> V_10 = ( void * ) F_4 ( V_13 |
V_14 ,
F_5 ( V_15 ) ) ;
if ( ! F_3 ( V_2 ) -> V_10 )
return - V_16 ;
F_6 ( F_3 ( V_2 ) -> V_10 , V_4 ,
V_15 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ )
F_3 ( V_2 ) -> V_18 [ V_9 ] = ( V_3 >> V_19 ) + V_9 ;
V_8 = ( T_3 * ) F_3 ( V_2 ) -> V_10 ;
V_8 [ V_20 ] = 0x3 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , bool V_21 )
{
T_4 V_22 ;
int V_9 , V_23 ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
V_22 = F_8 ( F_3 ( V_2 ) -> V_10
+ V_9 * V_24 ) ;
if ( V_22 == V_25 ) {
F_9 ( L_2 ) ;
return - V_12 ;
}
V_23 = F_10 ( V_2 ,
F_3 ( V_2 ) -> V_18 [ V_9 ] ,
V_22 , 1 , V_21 ) ;
if ( V_23 ) {
F_9 ( L_3 , V_23 ) ;
return V_23 ;
}
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( L_4 , V_2 -> V_11 ) ;
if ( ! F_3 ( V_2 ) -> V_10 )
return;
if ( V_26 . V_27 == V_28 ) {
F_7 ( V_2 , false ) ;
F_13 ( ( unsigned long ) F_3 ( V_2 ) -> V_10 ,
F_5 ( V_15 ) ) ;
F_3 ( V_2 ) -> V_10 = NULL ;
}
}
int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_23 ;
F_12 ( L_5 , V_2 -> V_11 ) ;
if ( V_26 . V_27 == V_28 ) {
F_12 ( L_6 ) ;
V_23 = F_1 ( V_2 , V_3 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_7 ( V_2 , true ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
void F_15 ( struct V_29 * V_5 )
{
F_16 ( V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_7 = NULL ;
}
int F_17 ( struct V_29 * V_5 )
{
F_12 ( L_7 ) ;
F_18 ( V_5 -> V_30 -> V_31 . V_32 , V_33 ,
& V_5 -> V_6 . V_34 ) ;
V_5 -> V_6 . V_7 = F_19 ( V_5 -> V_6 . V_34 ,
V_15 , V_35 ) ;
if ( ! V_5 -> V_6 . V_7 ) {
F_9 ( L_8 ) ;
return - V_36 ;
}
return 0 ;
}
static const char * F_20 ( T_1 V_37 )
{
const char * V_38 = NULL ;
switch ( V_37 ) {
case 0 ... 3 :
case 5 :
case 7 ... 15 :
V_38 = L_9 ;
break;
case 4 :
V_38 = L_10 ;
break;
case 6 :
V_38 = L_11 ;
break;
default:
V_38 = L_12 ;
break;
}
return V_38 ;
}
static const char * F_21 ( T_1 V_39 )
{
const char * V_38 = NULL ;
switch ( V_39 ) {
case 0 :
V_38 = L_13 ;
break;
case 1 :
V_38 = L_14 ;
break;
case 2 ... 3 :
case 8 ... 9 :
V_38 = L_9 ;
break;
case 5 :
V_38 = L_15 ;
break;
case 6 :
V_38 = L_16 ;
break;
case 7 :
V_38 = L_17 ;
break;
case 10 :
V_38 = L_18 ;
break;
case 11 :
V_38 = L_19 ;
break;
default:
V_38 = L_12 ;
break;
}
return V_38 ;
}
static bool F_22 ( T_1 V_40 )
{
T_1 V_37 , V_39 ;
V_37 = F_23 ( V_40 ) ;
V_39 = F_24 ( V_40 ) ;
if ( ( V_37 == V_41 &&
V_39 == V_42 )
|| ( V_37 == V_41 &&
V_39 == V_43 )
|| ( V_37 == V_44 &&
V_39 == V_42 ) ) {
return true ;
}
return false ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_45 )
{
T_1 * V_40 , * V_46 ;
T_1 V_37 , V_39 ;
V_40 = F_3 ( V_2 ) -> V_10 + V_47 ;
V_46 = F_3 ( V_2 ) -> V_10 + V_48 ;
if ( ! ( V_45 & V_49 ) ) {
F_9 ( L_20 , V_2 -> V_11 ) ;
return 0 ;
}
if ( ( F_26 ( V_2 ) [ V_50 ]
& V_51 ) ||
! ( V_45 & V_51 ) ) {
return 0 ;
}
V_37 = F_23 ( * V_40 ) ;
V_39 = F_24 ( * V_40 ) ;
if ( ! F_22 ( * V_40 ) ) {
F_9 ( L_21
L_22 ,
V_2 -> V_11 ,
F_20 ( V_37 ) ,
F_21 ( V_39 ) ) ;
* V_40 &= ~ V_52 ;
return 0 ;
}
* V_40 = 0 ;
* V_46 = 0 ;
return 0 ;
}
