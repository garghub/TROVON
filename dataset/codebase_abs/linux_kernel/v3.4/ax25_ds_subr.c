void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 ) ;
}
void F_3 ( T_1 * V_1 )
{
T_1 * V_2 ;
struct V_3 * V_4 ;
F_4 ( V_1 ) ;
if ( ! ( V_1 -> V_5 & V_6 ) ) {
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
}
if ( V_1 -> V_7 == V_8 || V_1 -> V_7 == V_9 || F_7 ( & V_1 -> V_10 ) != NULL )
F_8 ( V_1 ) ;
else
V_1 -> V_11 = 0 ;
F_9 ( V_1 ) ;
F_10 ( V_1 -> V_12 ) ;
F_11 ( & V_13 ) ;
F_12 (ax25o, node, &ax25_list) {
if ( V_2 == V_1 )
continue;
if ( V_2 -> V_12 != V_1 -> V_12 )
continue;
if ( V_2 -> V_7 == V_8 || V_2 -> V_7 == V_9 ) {
F_8 ( V_2 ) ;
continue;
}
if ( ! ( V_2 -> V_5 & V_6 ) && V_2 -> V_7 == V_14 ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
if ( V_2 -> V_7 == V_8 || V_2 -> V_7 == V_9 || F_7 ( & V_2 -> V_10 ) != NULL )
F_8 ( V_2 ) ;
if ( V_2 -> V_7 != V_15 )
F_9 ( V_2 ) ;
}
F_13 ( & V_13 ) ;
}
void F_2 ( T_1 * V_1 )
{
V_1 -> V_5 &= V_16 ;
V_1 -> V_11 = 0 ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_9 ( V_1 ) ;
}
static void F_17 ( V_12 * V_12 , unsigned char V_17 , unsigned char V_18 )
{
struct V_19 * V_20 ;
unsigned char * V_21 ;
if ( V_12 -> V_22 == NULL )
return;
if ( ( V_20 = F_18 ( 2 , V_23 ) ) == NULL )
return;
F_19 ( V_20 ) ;
V_21 = F_20 ( V_20 , 2 ) ;
* V_21 ++ = V_17 ;
* V_21 ++ = V_18 ;
V_20 -> V_24 = F_21 ( V_20 , V_12 -> V_22 ) ;
F_22 ( V_20 ) ;
}
static int F_23 ( V_12 * V_12 )
{
T_1 * V_1 ;
int V_25 = 0 ;
struct V_3 * V_4 ;
F_11 ( & V_13 ) ;
F_12 (ax25, node, &ax25_list)
if ( V_1 -> V_12 == V_12 && ( V_1 -> V_5 & V_16 ) && V_1 -> V_7 > V_8 ) {
V_25 = 1 ;
break;
}
F_13 ( & V_13 ) ;
return V_25 ;
}
static void F_24 ( V_12 * V_12 )
{
if ( V_12 == NULL )
return;
if ( V_12 -> V_26 . V_27 == 0 )
F_17 ( V_12 , 5 , 1 ) ;
V_12 -> V_26 . V_27 = 1 ;
F_10 ( V_12 ) ;
}
void F_25 ( V_12 * V_12 )
{
if ( V_12 == NULL )
return;
if ( V_12 -> V_26 . V_27 && ! F_23 ( V_12 ) ) {
F_17 ( V_12 , 5 , 0 ) ;
V_12 -> V_26 . V_27 = 0 ;
F_26 ( V_12 ) ;
}
}
void F_27 ( T_1 * V_1 )
{
F_24 ( V_1 -> V_12 ) ;
V_1 -> V_5 |= V_16 ;
}
void F_28 ( T_1 * V_1 )
{
V_1 -> V_5 &= ~ V_16 ;
F_25 ( V_1 -> V_12 ) ;
}
