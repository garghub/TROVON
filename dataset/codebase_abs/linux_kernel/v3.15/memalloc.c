void * F_1 ( T_1 V_1 , T_2 V_2 )
{
int V_3 ;
if ( F_2 ( ! V_1 ) )
return NULL ;
if ( F_2 ( ! V_2 ) )
return NULL ;
V_2 |= V_4 ;
V_3 = F_3 ( V_1 ) ;
return ( void * ) F_4 ( V_2 , V_3 ) ;
}
void F_5 ( void * V_5 , T_1 V_1 )
{
int V_3 ;
if ( V_5 == NULL )
return;
V_3 = F_3 ( V_1 ) ;
F_6 ( ( unsigned long ) V_5 , V_3 ) ;
}
static void * F_7 ( struct V_6 * V_7 , T_1 V_1 , T_3 * V_8 )
{
int V_3 ;
T_2 V_2 ;
if ( F_2 ( ! V_8 ) )
return NULL ;
V_3 = F_3 ( V_1 ) ;
V_2 = V_9
| V_4
| V_10
| V_11 ;
return F_8 ( V_7 , V_12 << V_3 , V_8 , V_2 ) ;
}
static void F_9 ( struct V_6 * V_7 , T_1 V_1 , void * V_5 ,
T_3 V_8 )
{
int V_3 ;
if ( V_5 == NULL )
return;
V_3 = F_3 ( V_1 ) ;
F_10 ( V_7 , V_12 << V_3 , V_5 , V_8 ) ;
}
static void F_11 ( struct V_13 * V_14 , T_1 V_1 )
{
struct V_6 * V_7 = V_14 -> V_7 . V_7 ;
struct V_15 * V_16 = NULL ;
V_14 -> V_17 = NULL ;
V_14 -> V_18 = 0 ;
if ( V_7 -> V_19 )
V_16 = F_12 ( V_7 -> V_19 , L_1 , 0 ) ;
if ( ! V_16 )
return;
V_14 -> V_20 = V_16 ;
V_14 -> V_17 = F_13 ( V_16 , V_1 , & V_14 -> V_18 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_20 ;
if ( V_16 && V_14 -> V_17 )
F_15 ( V_16 , ( unsigned long ) V_14 -> V_17 , V_14 -> V_21 ) ;
}
int F_16 ( int type , struct V_6 * V_6 , T_1 V_1 ,
struct V_13 * V_14 )
{
if ( F_2 ( ! V_1 ) )
return - V_22 ;
if ( F_2 ( ! V_14 ) )
return - V_22 ;
V_14 -> V_7 . type = type ;
V_14 -> V_7 . V_7 = V_6 ;
V_14 -> V_21 = 0 ;
switch ( type ) {
case V_23 :
V_14 -> V_17 = F_1 ( V_1 ,
( V_24 T_2 ) ( unsigned long ) V_6 ) ;
V_14 -> V_18 = 0 ;
break;
#ifdef F_17
#ifdef F_18
case V_25 :
F_11 ( V_14 , V_1 ) ;
if ( V_14 -> V_17 )
break;
V_14 -> V_7 . type = V_26 ;
#endif
case V_26 :
V_14 -> V_17 = F_7 ( V_6 , V_1 , & V_14 -> V_18 ) ;
break;
#endif
#ifdef F_19
case V_27 :
F_20 ( V_6 , V_1 , V_14 , NULL ) ;
break;
#endif
default:
F_21 ( L_2 , type ) ;
V_14 -> V_17 = NULL ;
V_14 -> V_18 = 0 ;
return - V_22 ;
}
if ( ! V_14 -> V_17 )
return - V_28 ;
V_14 -> V_21 = V_1 ;
return 0 ;
}
int F_22 ( int type , struct V_6 * V_6 , T_1 V_1 ,
struct V_13 * V_14 )
{
int V_29 ;
while ( ( V_29 = F_16 ( type , V_6 , V_1 , V_14 ) ) < 0 ) {
T_1 V_30 ;
if ( V_29 != - V_28 )
return V_29 ;
if ( V_1 <= V_12 )
return - V_28 ;
V_30 = V_12 << F_3 ( V_1 ) ;
if ( V_1 != V_30 )
V_1 = V_30 ;
else
V_1 >>= 1 ;
}
if ( ! V_14 -> V_17 )
return - V_28 ;
return 0 ;
}
void F_23 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_7 . type ) {
case V_23 :
F_5 ( V_14 -> V_17 , V_14 -> V_21 ) ;
break;
#ifdef F_17
#ifdef F_18
case V_25 :
F_14 ( V_14 ) ;
break;
#endif
case V_26 :
F_9 ( V_14 -> V_7 . V_7 , V_14 -> V_21 , V_14 -> V_17 , V_14 -> V_18 ) ;
break;
#endif
#ifdef F_19
case V_27 :
F_24 ( V_14 ) ;
break;
#endif
default:
F_21 ( L_2 , V_14 -> V_7 . type ) ;
}
}
