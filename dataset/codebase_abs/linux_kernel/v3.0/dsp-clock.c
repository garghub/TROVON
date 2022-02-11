static inline T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
return V_1 & ( 1 << V_2 ) ;
}
static inline void F_2 ( T_1 * V_1 , T_2 V_2 )
{
* V_1 |= ( 1 << V_2 ) ;
}
static inline void F_3 ( T_1 * V_1 , T_2 V_2 )
{
* V_1 &= ~ ( 1 << V_2 ) ;
}
static T_3 F_4 ( T_2 V_2 )
{
T_3 type ;
if ( V_2 == V_3 )
type = V_4 ;
else if ( V_2 <= V_5 )
type = V_6 ;
else if ( V_2 == V_7 )
type = V_8 ;
else if ( V_2 <= V_9 )
type = V_10 ;
else if ( V_2 == V_11 )
type = V_12 ;
else
type = - 1 ;
return type ;
}
void F_5 ( void )
{
F_6 ( V_13 ) ;
F_7 ( V_14 ) ;
F_7 ( V_15 . V_16 ) ;
F_7 ( V_15 . V_17 ) ;
F_7 ( V_15 . V_18 ) ;
}
void F_8 ( void )
{
static struct V_19 V_20 ;
V_20 . V_21 . V_22 = & V_23 ;
V_14 = F_9 ( & V_20 . V_21 , L_1 ) ;
if ( F_10 ( V_14 ) )
F_11 ( V_24 , L_2 , V_14 ) ;
V_15 . V_16 = F_9 ( & V_20 . V_21 , L_3 ) ;
V_15 . V_17 = F_9 ( & V_20 . V_21 , L_4 ) ;
V_15 . V_18 = F_9 ( & V_20 . V_21 , L_5 ) ;
if ( F_10 ( V_15 . V_16 ) || F_10 ( V_15 . V_17 ) || F_10 ( V_15 . V_18 ) )
F_11 ( V_24 , L_6 ,
V_15 . V_16 , V_15 . V_17 , V_15 . V_18 ) ;
}
void F_12 ( short int V_25 , unsigned int V_26 )
{
struct V_27 * V_28 = V_29 [ V_25 - 1 ] ;
unsigned long V_30 ;
if ( ! V_28 )
return;
F_13 ( V_28 , V_31 ) ;
F_14 ( V_28 , 0 , V_26 ) ;
F_15 ( 80 ) ;
V_30 = F_16 ( 5 ) ;
while ( ! ( F_17 ( V_28 ) & V_31 ) ) {
if ( F_18 ( V_30 ) ) {
F_19 ( L_7 , V_32 ) ;
break;
}
}
}
int F_20 ( enum V_33 V_25 )
{
int V_34 = 0 ;
if ( F_1 ( V_13 , V_25 ) ) {
F_11 ( V_24 , L_8 , V_25 ) ;
goto V_35;
}
switch ( F_4 ( V_25 ) ) {
case V_4 :
F_21 ( V_14 ) ;
break;
case V_6 :
V_29 [ V_25 - 1 ] =
F_22 ( F_23 ( V_25 ) ) ;
break;
#ifdef F_24
case V_10 :
F_25 ( F_26 ( V_25 ) , V_36 ) ;
F_27 ( F_26 ( V_25 ) ) ;
F_28 ( F_26 ( V_25 ) , V_37 ) ;
break;
#endif
case V_8 :
F_11 ( V_24 , L_9 ) ;
break;
case V_12 :
F_21 ( V_15 . V_16 ) ;
F_21 ( V_15 . V_17 ) ;
F_21 ( V_15 . V_18 ) ;
F_29 ( true ) ;
break;
default:
F_11 ( V_24 , L_10 ) ;
V_34 = - V_38 ;
}
if ( ! V_34 )
F_2 ( & V_13 , V_25 ) ;
V_35:
return V_34 ;
}
T_1 F_30 ( T_1 V_39 )
{
T_1 V_25 ;
T_1 V_34 = - V_38 ;
for ( V_25 = 0 ; V_25 < V_40 ; V_25 ++ ) {
if ( F_1 ( V_39 , V_25 ) )
V_34 = F_20 ( V_25 ) ;
}
return V_34 ;
}
int F_31 ( enum V_33 V_25 )
{
int V_34 = 0 ;
if ( ! F_1 ( V_13 , V_25 ) ) {
F_11 ( V_24 , L_11 , V_25 ) ;
goto V_35;
}
switch ( F_4 ( V_25 ) ) {
case V_4 :
F_32 ( V_14 ) ;
break;
case V_6 :
F_33 ( V_29 [ V_25 - 1 ] ) ;
break;
#ifdef F_24
case V_10 :
F_28 ( F_26 ( V_25 ) , V_41 ) ;
F_34 ( F_26 ( V_25 ) ) ;
break;
#endif
case V_8 :
F_11 ( V_24 , L_12 ) ;
break;
case V_12 :
F_29 ( false ) ;
F_29 ( false ) ;
F_32 ( V_15 . V_16 ) ;
F_32 ( V_15 . V_17 ) ;
F_32 ( V_15 . V_18 ) ;
break;
default:
F_11 ( V_24 , L_13 ) ;
V_34 = - V_38 ;
}
if ( ! V_34 )
F_3 ( & V_13 , V_25 ) ;
V_35:
return V_34 ;
}
T_1 F_6 ( T_1 V_39 )
{
T_1 V_25 ;
T_1 V_34 = - V_38 ;
for ( V_25 = 0 ; V_25 < V_40 ; V_25 ++ ) {
if ( F_1 ( V_39 , V_25 ) )
V_34 = F_31 ( V_25 ) ;
}
return V_34 ;
}
T_1 F_35 ( void )
{
T_1 V_42 ;
V_42 = F_36 ( V_14 ) ;
V_42 /= 1000 ;
F_37 ( V_24 , L_14 , V_32 , V_42 ) ;
return V_42 ;
}
void F_29 ( bool V_43 )
{
void T_4 * V_44 ;
unsigned int V_45 ;
V_44 = F_38 ( V_46 + V_47 , V_48 ) ;
if ( ! V_44 ) {
F_19 ( L_15 , V_32 ) ;
return;
}
if ( V_43 ) {
V_45 = V_49 | V_50 | V_51 ;
} else {
V_45 = V_49 ;
}
F_39 ( V_45 , V_44 + V_52 ) ;
F_40 ( V_44 ) ;
}
