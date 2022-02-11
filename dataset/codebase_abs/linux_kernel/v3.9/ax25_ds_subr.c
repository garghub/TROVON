void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 ) ;
}
void F_3 ( T_1 * V_1 )
{
T_1 * V_2 ;
F_4 ( V_1 ) ;
if ( ! ( V_1 -> V_3 & V_4 ) ) {
F_5 ( V_1 ) ;
F_6 ( V_1 ) ;
}
if ( V_1 -> V_5 == V_6 || V_1 -> V_5 == V_7 || F_7 ( & V_1 -> V_8 ) != NULL )
F_8 ( V_1 ) ;
else
V_1 -> V_9 = 0 ;
F_9 ( V_1 ) ;
F_10 ( V_1 -> V_10 ) ;
F_11 ( & V_11 ) ;
F_12 (ax25o, &ax25_list) {
if ( V_2 == V_1 )
continue;
if ( V_2 -> V_10 != V_1 -> V_10 )
continue;
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_7 ) {
F_8 ( V_2 ) ;
continue;
}
if ( ! ( V_2 -> V_3 & V_4 ) && V_2 -> V_5 == V_12 ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
}
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_7 || F_7 ( & V_2 -> V_8 ) != NULL )
F_8 ( V_2 ) ;
if ( V_2 -> V_5 != V_13 )
F_9 ( V_2 ) ;
}
F_13 ( & V_11 ) ;
}
void F_2 ( T_1 * V_1 )
{
V_1 -> V_3 &= V_14 ;
V_1 -> V_9 = 0 ;
F_14 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 ) ;
F_9 ( V_1 ) ;
}
static void F_17 ( V_10 * V_10 , unsigned char V_15 , unsigned char V_16 )
{
struct V_17 * V_18 ;
unsigned char * V_19 ;
if ( V_10 -> V_20 == NULL )
return;
if ( ( V_18 = F_18 ( 2 , V_21 ) ) == NULL )
return;
F_19 ( V_18 ) ;
V_19 = F_20 ( V_18 , 2 ) ;
* V_19 ++ = V_15 ;
* V_19 ++ = V_16 ;
V_18 -> V_22 = F_21 ( V_18 , V_10 -> V_20 ) ;
F_22 ( V_18 ) ;
}
static int F_23 ( V_10 * V_10 )
{
T_1 * V_1 ;
int V_23 = 0 ;
F_11 ( & V_11 ) ;
F_12 (ax25, &ax25_list)
if ( V_1 -> V_10 == V_10 && ( V_1 -> V_3 & V_14 ) && V_1 -> V_5 > V_6 ) {
V_23 = 1 ;
break;
}
F_13 ( & V_11 ) ;
return V_23 ;
}
static void F_24 ( V_10 * V_10 )
{
if ( V_10 == NULL )
return;
if ( V_10 -> V_24 . V_25 == 0 )
F_17 ( V_10 , 5 , 1 ) ;
V_10 -> V_24 . V_25 = 1 ;
F_10 ( V_10 ) ;
}
void F_25 ( V_10 * V_10 )
{
if ( V_10 == NULL )
return;
if ( V_10 -> V_24 . V_25 && ! F_23 ( V_10 ) ) {
F_17 ( V_10 , 5 , 0 ) ;
V_10 -> V_24 . V_25 = 0 ;
F_26 ( V_10 ) ;
}
}
void F_27 ( T_1 * V_1 )
{
F_24 ( V_1 -> V_10 ) ;
V_1 -> V_3 |= V_14 ;
}
void F_28 ( T_1 * V_1 )
{
V_1 -> V_3 &= ~ V_14 ;
F_25 ( V_1 -> V_10 ) ;
}
