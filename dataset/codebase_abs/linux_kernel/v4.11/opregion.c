static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 ;
int V_5 ;
if ( F_2 ( ( F_3 ( V_2 ) -> V_6 ) ,
L_1 ,
V_2 -> V_7 ) )
return - V_8 ;
F_3 ( V_2 ) -> V_6 = ( void * ) F_4 ( V_9 |
V_10 ,
F_5 ( V_11 ) ) ;
if ( ! F_3 ( V_2 ) -> V_6 )
return - V_12 ;
memcpy ( F_3 ( V_2 ) -> V_6 , V_2 -> V_13 -> V_14 . V_15 ,
V_11 ) ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
F_3 ( V_2 ) -> V_17 [ V_5 ] = ( V_3 >> V_18 ) + V_5 ;
V_4 = ( T_2 * ) F_3 ( V_2 ) -> V_6 ;
V_4 [ V_19 ] = 0x3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , bool V_20 )
{
T_3 V_21 ;
int V_5 , V_22 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
V_21 = F_7 ( F_3 ( V_2 ) -> V_6
+ V_5 * V_23 ) ;
if ( V_21 == V_24 ) {
F_8 ( L_2 ) ;
return - V_8 ;
}
V_22 = F_9 ( V_2 ,
F_3 ( V_2 ) -> V_17 [ V_5 ] ,
V_21 , 1 , V_20 ) ;
if ( V_22 ) {
F_8 ( L_3 ,
V_22 ) ;
return V_22 ;
}
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( L_4 , V_2 -> V_7 ) ;
if ( ! F_3 ( V_2 ) -> V_6 )
return;
if ( V_25 . V_26 == V_27 ) {
F_6 ( V_2 , false ) ;
F_12 ( ( unsigned long ) F_3 ( V_2 ) -> V_6 ,
F_5 ( V_11 ) ) ;
F_3 ( V_2 ) -> V_6 = NULL ;
}
}
int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_22 ;
F_11 ( L_5 , V_2 -> V_7 ) ;
if ( V_25 . V_26 == V_27 ) {
F_11 ( L_6 ) ;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_6 ( V_2 , true ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
void F_14 ( struct V_28 * V_13 )
{
F_15 ( V_13 -> V_14 . V_15 ) ;
V_13 -> V_14 . V_15 = NULL ;
}
int F_16 ( struct V_28 * V_13 )
{
F_11 ( L_7 ) ;
F_17 ( V_13 -> V_29 -> V_30 . V_31 , V_32 ,
& V_13 -> V_14 . V_33 ) ;
V_13 -> V_14 . V_15 = F_18 ( V_13 -> V_14 . V_33 ,
V_11 , V_34 ) ;
if ( ! V_13 -> V_14 . V_15 ) {
F_19 ( L_8 ) ;
return - V_35 ;
}
return 0 ;
}
static const char * F_20 ( T_1 V_36 )
{
const char * V_37 = NULL ;
switch ( V_36 ) {
case 0 ... 3 :
case 5 :
case 7 ... 15 :
V_37 = L_9 ;
break;
case 4 :
V_37 = L_10 ;
break;
case 6 :
V_37 = L_11 ;
break;
default:
V_37 = L_12 ;
break;
}
return V_37 ;
}
static const char * F_21 ( T_1 V_38 )
{
const char * V_37 = NULL ;
switch ( V_38 ) {
case 0 :
V_37 = L_13 ;
break;
case 1 :
V_37 = L_14 ;
break;
case 2 ... 3 :
case 8 ... 9 :
V_37 = L_9 ;
break;
case 5 :
V_37 = L_15 ;
break;
case 6 :
V_37 = L_16 ;
break;
case 7 :
V_37 = L_17 ;
break;
case 10 :
V_37 = L_18 ;
break;
case 11 :
V_37 = L_19 ;
break;
default:
V_37 = L_12 ;
break;
}
return V_37 ;
}
static bool F_22 ( T_1 V_39 )
{
T_1 V_36 , V_38 ;
V_36 = F_23 ( V_39 ) ;
V_38 = F_24 ( V_39 ) ;
if ( ( V_36 == V_40 &&
V_38 == V_41 )
|| ( V_36 == V_40 &&
V_38 == V_42 )
|| ( V_36 == V_43 &&
V_38 == V_41 ) ) {
return true ;
}
return false ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_44 )
{
T_1 * V_39 , * V_45 ;
T_1 V_36 , V_38 ;
V_39 = F_3 ( V_2 ) -> V_6 + V_46 ;
V_45 = F_3 ( V_2 ) -> V_6 + V_47 ;
if ( ! ( V_44 & V_48 ) ) {
F_8 ( L_20 ) ;
return 0 ;
}
if ( ( F_26 ( V_2 ) [ V_49 ]
& V_50 ) ||
! ( V_44 & V_50 ) ) {
return 0 ;
}
V_36 = F_23 ( * V_39 ) ;
V_38 = F_24 ( * V_39 ) ;
if ( ! F_22 ( * V_39 ) ) {
F_8 ( L_21
L_22 ,
F_20 ( V_36 ) ,
F_21 ( V_38 ) ) ;
* V_39 &= ~ V_51 ;
return 0 ;
}
* V_39 = 0 ;
* V_45 = 0 ;
return 0 ;
}
