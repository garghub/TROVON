static int F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = F_3 ( NULL ,
F_4 ( 'N' , 'I' , 'C' ) ,
F_5 ( V_5 [ V_4 ] .
V_6 ) , NULL ) ;
if ( V_3 == NULL || V_3 -> V_7 == NULL )
continue;
if ( F_6 ( V_3 ) < 0 )
continue;
if ( F_7 ( V_3 ) < 0 ) {
F_8 ( V_3 ) ;
return - V_8 ;
}
if ( ! F_9 ( V_3 , 0 ) ||
! F_10 ( V_3 , 0 ) ) {
F_8 ( V_3 ) ;
return - V_9 ;
}
break;
}
if ( V_4 == F_2 ( V_5 ) )
return - V_10 ;
* V_2 = V_3 ;
return 0 ;
}
static int F_11 ( struct V_11 * V_2 )
{
int V_12 = F_12 ( V_2 , 511 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_12 == V_12 )
return V_4 ;
}
if ( V_12 == 255 )
F_13 ( V_2 -> V_13 , L_1 ) ;
else if ( V_12 == 0 )
F_13 ( V_2 -> V_13 ,
L_2 ) ;
else
F_13 ( V_2 -> V_13 ,
L_3 , V_12 ) ;
return - 1 ;
}
static int F_14 ( struct V_11 * V_2 ,
struct V_14 * V_15 )
{
const struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_1 * V_3 ;
int V_20 ;
unsigned long V_21 ;
int V_22 ;
unsigned int V_23 ;
V_20 = F_15 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_19 = V_2 -> V_24 ;
V_21 = V_15 -> V_25 [ 0 ] ;
V_23 = V_15 -> V_25 [ 1 ] ;
V_3 = NULL ;
if ( V_21 == 0 ) {
V_20 = F_1 ( & V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
V_21 = F_16 ( V_3 , 0 ) ;
V_23 = F_17 ( V_3 , 0 ) ;
F_18 ( V_2 , & V_3 -> V_2 ) ;
}
V_20 = F_19 ( V_2 , V_21 , 0x20 ) ;
if ( V_20 )
return V_20 ;
V_22 = F_11 ( V_2 ) ;
if ( V_22 < 0 )
return - V_26 ;
V_2 -> V_27 = V_5 + V_22 ;
V_17 = F_20 ( V_2 ) ;
V_2 -> V_28 = V_17 -> V_29 ;
if ( V_23 != 0 ) {
if ( V_23 > 15 || V_30 [ V_23 ] == - 1 )
return - V_31 ;
V_20 = F_21 ( V_23 , V_32 , 0 ,
V_2 -> V_28 , V_2 ) ;
if ( V_20 < 0 )
return - V_31 ;
V_2 -> V_23 = V_23 ;
}
V_20 = F_22 ( V_2 , V_30 [ V_2 -> V_23 ] , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static void F_23 ( struct V_11 * V_2 )
{
struct V_1 * V_3 ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
V_3 = V_2 -> V_33 ? F_26 ( V_2 -> V_33 ) : NULL ;
if ( V_3 )
F_8 ( V_3 ) ;
}
