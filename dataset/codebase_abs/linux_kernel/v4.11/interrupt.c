void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_3 , & V_2 -> V_4 . V_5 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_4 ( V_3 , & V_2 -> V_4 . V_5 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_4 . V_6 , ( V_7 | V_8 ) ) ;
F_1 ( V_2 , V_9 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_4 . V_6 , ( V_7 | V_8 ) ) ;
F_3 ( V_2 , V_9 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_12 = ( int ) V_11 -> V_11 ;
switch ( V_12 ) {
case 2 :
F_6 ( V_2 -> V_4 . V_6 , ( V_13 ) ) ;
F_1 ( V_2 , V_14 ) ;
break;
case 3 :
F_6 ( V_2 -> V_4 . V_6 , ( V_15 ) ) ;
F_1 ( V_2 , V_16 ) ;
break;
case 4 :
F_6 ( V_2 -> V_4 . V_6 , ( V_17 ) ) ;
F_1 ( V_2 , V_18 ) ;
break;
default:
break;
}
}
void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_12 = ( int ) V_11 -> V_11 ;
switch ( V_12 ) {
case - 2 :
F_8 ( V_2 -> V_4 . V_6 , ( V_13 ) ) ;
F_3 ( V_2 , V_14 ) ;
break;
case - 3 :
F_8 ( V_2 -> V_4 . V_6 , ( V_15 ) ) ;
F_3 ( V_2 , V_16 ) ;
break;
case - 4 :
F_8 ( V_2 -> V_4 . V_6 , ( V_17 ) ) ;
F_3 ( V_2 , V_18 ) ;
break;
default:
break;
}
}
int F_11 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_19 )
{
int V_20 = 0 ;
T_1 V_21 ;
struct V_22 * V_4 = & V_2 -> V_4 ;
struct V_23 * V_6 = V_2 -> V_4 . V_6 ;
switch ( V_3 ) {
case V_9 :
if ( ( F_12 ( V_6 ) & V_24 )
&& ( ! ( F_12 ( V_6 ) & ( V_25 | V_26 ) ) )
&& ( F_12 ( V_6 ) & V_27 ) ) {
V_20 = 1 ;
V_21 = V_28 ;
}
break;
case V_14 :
if ( ( F_12 ( V_6 ) & V_24 )
&& ( ! ( F_12 ( V_6 ) & ( V_25 | V_26 ) ) )
&& ( F_12 ( V_6 ) & V_29 ) ) {
V_20 = 1 ;
V_21 = V_28 ;
}
break;
case V_16 :
if ( ( F_12 ( V_6 ) & V_24 )
&& ( ! ( F_12 ( V_6 ) & ( V_25 | V_26 ) ) )
&& ( F_12 ( V_6 ) & V_30 ) ) {
V_20 = 1 ;
V_21 = V_28 ;
}
break;
case V_18 :
if ( ( F_12 ( V_6 ) & V_24 )
&& ( ! ( F_12 ( V_6 ) & ( V_25 | V_26 ) ) )
&& ( F_12 ( V_6 ) & V_31 ) ) {
V_20 = 1 ;
V_21 = V_28 ;
}
break;
default:
break;
}
if ( V_20 ) {
if ( ( F_12 ( V_6 ) & V_25 ) == 0 ) {
F_13 ( V_6 , V_4 -> V_32 ) ;
F_14 ( V_6 , V_25 ) ;
if ( V_19 & V_33 )
F_6 ( V_6 , V_33 ) ;
else
F_8 ( V_6 , V_33 ) ;
F_15 ( L_1 , V_4 -> V_32 ) ;
} else
F_16 ( L_2 ) ;
F_17 ( V_6 , V_34 ,
( V_21 << V_35 ) ) ;
V_4 -> V_32 = F_18 ( V_2 ) ;
if ( F_19 ( V_6 ) & V_36 )
V_4 -> V_32 += 0x200 ;
else
V_4 -> V_32 += 0x180 ;
F_4 ( V_3 , & V_2 -> V_4 . V_5 ) ;
}
return V_20 ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_19 )
{
return 1 ;
}
void F_21 ( struct V_1 * V_2 , T_1 V_19 )
{
unsigned long * V_37 = & V_2 -> V_4 . V_5 ;
unsigned long * V_38 = & V_2 -> V_4 . V_39 ;
unsigned int V_3 ;
if ( ! ( * V_37 ) && ! ( * V_38 ) )
return;
V_3 = F_22 ( * V_38 ) ;
while ( V_3 <= V_40 ) {
if ( V_41 -> V_42 ( V_2 , V_3 , V_19 ) ) {
if ( ! V_43 )
break;
}
V_3 = F_23 ( V_38 ,
V_44 * sizeof( * V_38 ) ,
V_3 + 1 ) ;
}
V_3 = F_22 ( * V_37 ) ;
while ( V_3 <= V_40 ) {
if ( V_41 -> V_45 ( V_2 , V_3 , V_19 ) ) {
if ( ! V_46 )
break;
}
V_3 = F_23 ( V_37 ,
V_44 * sizeof( * V_37 ) ,
V_3 + 1 ) ;
}
}
int F_24 ( struct V_1 * V_2 )
{
return F_25 ( V_9 , & V_2 -> V_4 . V_5 ) ;
}
