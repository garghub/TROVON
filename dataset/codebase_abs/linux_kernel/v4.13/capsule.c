bool F_1 ( int * V_1 )
{
if ( ! V_2 )
return false ;
if ( V_1 )
* V_1 = V_3 ;
return true ;
}
int F_2 ( T_1 V_4 , T_2 V_5 , T_3 V_6 , int * V_7 )
{
T_4 V_8 ;
T_4 * V_9 [] = { & V_8 } ;
T_5 V_10 ;
T_6 V_11 ;
if ( V_5 & ~ V_12 )
return - V_13 ;
V_8 . V_14 = V_8 . V_15 = sizeof( V_8 ) ;
memcpy ( & V_8 . V_4 , & V_4 , sizeof( T_1 ) ) ;
V_8 . V_5 = V_5 ;
V_10 = V_16 . V_17 ( V_9 , 1 , & V_11 , V_7 ) ;
if ( V_10 != V_18 )
return F_3 ( V_10 ) ;
if ( V_6 > V_11 )
return - V_19 ;
return 0 ;
}
static inline unsigned int F_4 ( unsigned int V_20 )
{
return F_5 ( V_20 , V_21 ) ;
}
static int
F_6 ( T_4 * V_8 ,
struct V_22 * * V_23 , int V_7 )
{
T_7 V_24 ;
T_5 V_10 ;
F_7 ( & V_25 ) ;
if ( V_3 >= 0 && V_3 != V_7 ) {
F_8 ( L_1 ,
V_7 , V_3 ) ;
return - V_13 ;
}
if ( F_9 ( V_26 ) ) {
F_10 ( L_2 ) ;
return - V_13 ;
}
V_24 = F_11 ( V_23 [ 0 ] ) ;
V_10 = V_16 . V_27 ( & V_8 , 1 , V_24 ) ;
if ( V_10 == V_18 ) {
V_2 = true ;
V_3 = V_7 ;
}
return F_3 ( V_10 ) ;
}
int F_12 ( T_4 * V_8 , T_8 * V_28 )
{
T_2 V_15 = V_8 -> V_15 ;
T_1 V_4 = V_8 -> V_4 ;
unsigned int V_20 , V_29 ;
T_2 V_5 = V_8 -> V_5 ;
struct V_22 * * V_23 ;
int V_30 , V_1 ;
int V_31 , V_32 ;
V_30 = F_2 ( V_4 , V_5 , V_15 , & V_1 ) ;
if ( V_30 )
return V_30 ;
V_20 = F_5 ( V_15 , V_33 ) ;
V_29 = F_4 ( V_20 ) ;
V_23 = F_13 ( V_29 * sizeof( * V_23 ) , V_34 ) ;
if ( ! V_23 )
return - V_35 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
V_23 [ V_31 ] = F_14 ( V_34 ) ;
if ( ! V_23 [ V_31 ] ) {
V_30 = - V_35 ;
goto V_36;
}
}
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ ) {
T_9 * V_37 ;
V_37 = F_15 ( V_23 [ V_31 ] ) ;
for ( V_32 = 0 ; V_32 < V_21 && V_20 > 0 ; V_32 ++ ) {
T_6 V_38 = F_16 ( T_6 , V_15 ,
V_33 - ( T_6 ) * V_28 % V_33 ) ;
V_37 [ V_32 ] . V_39 = V_38 ;
V_37 [ V_32 ] . V_40 = * V_28 ++ ;
V_15 -= V_38 ;
V_20 -- ;
}
V_37 [ V_32 ] . V_39 = 0 ;
if ( V_31 + 1 == V_29 )
V_37 [ V_32 ] . V_40 = 0 ;
else
V_37 [ V_32 ] . V_40 = F_11 ( V_23 [ V_31 + 1 ] ) ;
F_17 ( V_23 [ V_31 ] ) ;
}
F_18 ( & V_25 ) ;
V_30 = F_6 ( V_8 , V_23 , V_1 ) ;
F_19 ( & V_25 ) ;
V_36:
for ( V_31 = 0 ; V_30 && V_31 < V_29 ; V_31 ++ ) {
if ( V_23 [ V_31 ] )
F_20 ( V_23 [ V_31 ] ) ;
}
F_21 ( V_23 ) ;
return V_30 ;
}
static int F_22 ( struct V_41 * V_42 , unsigned long V_43 , void * V_44 )
{
F_18 ( & V_25 ) ;
V_26 = true ;
F_19 ( & V_25 ) ;
return V_45 ;
}
static int T_10 F_23 ( void )
{
return F_24 ( & V_46 ) ;
}
