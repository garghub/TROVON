void F_1 ( T_1 * V_1 )
{
F_2 ( & V_1 -> V_2 , V_3 , ( unsigned long ) V_1 ) ;
F_2 ( & V_1 -> V_4 , V_5 , ( unsigned long ) V_1 ) ;
F_2 ( & V_1 -> V_6 , V_7 , ( unsigned long ) V_1 ) ;
F_2 ( & V_1 -> V_8 , V_9 , ( unsigned long ) V_1 ) ;
F_2 ( & V_1 -> V_10 , V_11 ,
( unsigned long ) V_1 ) ;
}
void F_3 ( T_1 * V_1 )
{
F_4 ( & V_1 -> V_2 , V_12 + 5 * V_13 ) ;
}
void F_5 ( T_1 * V_1 )
{
F_4 ( & V_1 -> V_4 , V_12 + V_1 -> V_14 ) ;
}
void F_6 ( T_1 * V_1 )
{
F_4 ( & V_1 -> V_6 , V_12 + V_1 -> V_15 ) ;
}
void F_7 ( T_1 * V_1 )
{
if ( V_1 -> V_16 > 0 )
F_4 ( & V_1 -> V_8 , V_12 + V_1 -> V_16 ) ;
else
F_8 ( & V_1 -> V_8 ) ;
}
void F_9 ( T_1 * V_1 )
{
if ( V_1 -> V_17 > 0 )
F_4 ( & V_1 -> V_10 , V_12 + V_1 -> V_17 ) ;
else
F_8 ( & V_1 -> V_10 ) ;
}
void F_10 ( T_1 * V_1 )
{
F_8 ( & V_1 -> V_2 ) ;
}
void F_11 ( T_1 * V_1 )
{
F_8 ( & V_1 -> V_4 ) ;
}
void F_12 ( T_1 * V_1 )
{
F_8 ( & V_1 -> V_6 ) ;
}
void F_13 ( T_1 * V_1 )
{
F_8 ( & V_1 -> V_8 ) ;
}
void F_14 ( T_1 * V_1 )
{
F_8 ( & V_1 -> V_10 ) ;
}
int F_15 ( T_1 * V_1 )
{
return F_16 ( & V_1 -> V_4 ) ;
}
unsigned long F_17 ( struct V_18 * V_2 )
{
if ( ! F_16 ( V_2 ) )
return 0 ;
return V_2 -> V_19 - V_12 ;
}
static void V_3 ( unsigned long V_20 )
{
int V_21 = V_22 ;
T_1 * V_1 = ( T_1 * ) V_20 ;
if ( V_1 -> V_23 )
V_21 = V_1 -> V_23 -> V_24 [ V_25 ] ;
switch ( V_21 ) {
case V_22 :
case V_26 :
F_18 ( V_1 ) ;
break;
#ifdef F_19
case V_27 :
if ( V_1 -> V_23 -> V_28 . V_29 )
F_20 ( V_1 ) ;
else
F_18 ( V_1 ) ;
break;
#endif
}
}
static void V_5 ( unsigned long V_20 )
{
T_1 * V_1 = ( T_1 * ) V_20 ;
switch ( V_1 -> V_23 -> V_24 [ V_25 ] ) {
case V_22 :
case V_26 :
F_21 ( V_1 ) ;
break;
#ifdef F_19
case V_27 :
if ( ! V_1 -> V_23 -> V_28 . V_29 )
F_21 ( V_1 ) ;
break;
#endif
}
}
static void V_7 ( unsigned long V_20 )
{
T_1 * V_1 = ( T_1 * ) V_20 ;
switch ( V_1 -> V_23 -> V_24 [ V_25 ] ) {
case V_22 :
case V_26 :
F_22 ( V_1 ) ;
break;
#ifdef F_19
case V_27 :
if ( ! V_1 -> V_23 -> V_28 . V_29 )
F_22 ( V_1 ) ;
break;
#endif
}
}
static void V_9 ( unsigned long V_20 )
{
T_1 * V_1 = ( T_1 * ) V_20 ;
switch ( V_1 -> V_23 -> V_24 [ V_25 ] ) {
case V_22 :
case V_26 :
F_23 ( V_1 ) ;
break;
#ifdef F_19
case V_27 :
if ( V_1 -> V_23 -> V_28 . V_29 )
F_24 ( V_1 ) ;
else
F_23 ( V_1 ) ;
break;
#endif
}
}
static void V_11 ( unsigned long V_20 )
{
T_1 * V_1 = ( T_1 * ) V_20 ;
switch ( V_1 -> V_23 -> V_24 [ V_25 ] ) {
case V_22 :
case V_26 :
F_25 ( V_1 ) ;
break;
#ifdef F_19
case V_27 :
if ( V_1 -> V_23 -> V_28 . V_29 )
F_26 ( V_1 ) ;
else
F_25 ( V_1 ) ;
break;
#endif
}
}
