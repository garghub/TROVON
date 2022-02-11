int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_4 = F_2 () ;
V_3 = F_3 ( V_2 , V_5 [ V_4 ] ) ;
F_4 () ;
if ( V_3 )
F_5 ( V_6 L_1
L_2 , V_3 , V_2 -> V_7 ) ;
return V_3 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_4 = F_2 () ;
V_3 = F_7 ( V_2 , V_5 [ V_4 ] ) ;
F_4 () ;
if ( V_3 )
F_5 ( V_6 L_3
L_2 , V_3 , V_2 -> V_7 ) ;
return V_3 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
int V_13 ;
if ( ! V_11 -> V_14 . V_15 )
return V_16 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
if ( ! V_11 -> V_14 . V_15 [ V_13 ] . V_18 )
return V_13 + V_16 ;
return - V_19 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = 1 ;
}
static int F_10 ( int V_22 , struct V_8 * V_23 )
{
int V_3 = 0 ;
int V_13 ;
for ( V_13 = V_16 ; V_13 < V_24 ; V_13 ++ ) {
struct V_25 * V_26 =
& V_23 -> V_12 . V_14 . V_15 [ V_13 - V_16 ] ;
if ( ! V_26 -> V_18 ) {
if ( ! V_26 -> V_27 ) {
F_9 ( & V_26 -> V_28 ) ;
V_26 -> V_28 . V_7 = V_13 ;
} else {
F_11 ( ! F_12 ( & V_26 -> V_28 ) ) ;
continue;
}
}
if ( ! ( V_22 & V_29 ) && V_26 -> V_27 )
continue;
V_3 = F_1 ( & V_26 -> V_28 ) ;
if ( V_3 )
goto V_30;
V_26 -> V_27 = 1 ;
}
V_30:
return V_3 ;
}
static inline int F_13 ( struct V_8 * V_9 )
{
int V_31 ;
int V_3 = 0 ;
for ( V_31 = V_16 ; V_31 < V_24 ; V_31 ++ ) {
struct V_25 * V_26 =
& V_9 -> V_12 . V_14 . V_15 [ V_31 - V_16 ] ;
if ( V_26 -> V_27 )
continue;
V_3 = 1 ;
break;
}
return V_3 ;
}
void F_14 ( struct V_8 * V_9 )
{
int V_31 ;
for ( V_31 = V_16 ; V_31 < V_24 ; V_31 ++ ) {
struct V_25 * V_26 =
& V_9 -> V_12 . V_14 . V_15 [ V_31 - V_16 ] ;
if ( ! V_26 -> V_18 )
continue;
V_26 -> V_27 = 0 ;
}
}
int F_15 ( struct V_8 * V_23 )
{
if ( ! V_32 )
return 0 ;
if ( F_16 ( V_23 -> V_33 ) )
return F_10 ( V_29 , V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_13 , int V_27 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
if ( V_13 < V_16 || V_13 > V_24 )
return - V_34 ;
V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_28 = * V_2 ;
V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_18 = 1 ;
V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_27 = V_27 ;
return 0 ;
}
int F_18 ( struct V_8 * V_35 )
{
struct V_1 V_2 ;
int V_13 , V_3 = - V_36 ;
if ( F_19 ( & V_2 ,
( void V_37 * ) F_20 ( & V_35 -> V_12 . V_38 . V_38 ) ,
sizeof( V_2 ) ) )
goto V_30;
V_3 = - V_34 ;
if ( F_12 ( & V_2 ) )
goto V_30;
V_13 = V_2 . V_7 ;
V_3 = F_17 ( V_35 , & V_2 , V_13 , 0 ) ;
V_30:
return V_3 ;
}
static int F_21 ( struct V_8 * V_9 , struct V_1 * V_2 ,
int V_13 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_14 . V_15 )
goto V_39;
if ( V_13 < V_16 || V_13 > V_24 )
return - V_34 ;
if ( ! V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_18 )
goto V_39;
* V_2 = V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_28 ;
V_30:
if ( F_22 ( V_9 == V_40 &&
! V_11 -> V_14 . V_15 [ V_13 - V_16 ] . V_27 ) ) {
F_5 ( V_6 L_4
L_5 , V_40 -> V_41 ) ;
}
return 0 ;
V_39:
F_9 ( V_2 ) ;
V_2 -> V_7 = V_13 ;
goto V_30;
}
int F_23 ( struct V_8 * V_42 , int V_13 ,
struct V_1 V_37 * V_1 )
{
struct V_1 V_2 ;
if ( ! V_32 )
return - V_43 ;
if ( F_19 ( & V_2 , V_1 , sizeof( V_2 ) ) )
return - V_36 ;
return F_17 ( V_42 , & V_2 , V_13 , 0 ) ;
}
int F_24 ( struct V_8 * V_42 , int V_13 ,
struct V_1 V_37 * V_1 )
{
struct V_1 V_2 ;
int V_3 ;
if ( ! V_32 )
return - V_43 ;
V_3 = F_21 ( V_42 , & V_2 , V_13 ) ;
if ( V_3 < 0 )
goto V_30;
if ( F_25 ( V_1 , & V_2 , sizeof( V_2 ) ) )
V_3 = - V_36 ;
V_30:
return V_3 ;
}
static int T_2 F_26 ( void )
{
F_27 ( & V_32 , & V_44 ) ;
if ( V_32 ) {
F_5 ( V_45 L_6 ) ;
F_5 ( V_45 L_7 ) ;
switch ( V_44 ) {
case V_46 :
F_5 ( V_47 L_8 ) ;
break;
case V_48 :
F_5 ( V_47 L_9 ) ;
break;
}
F_5 ( V_47 L_10 ,
V_44 ,
V_44 + V_17 ) ;
} else
F_5 ( V_6 L_11
L_12 ) ;
return 0 ;
}
