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
struct V_1 * V_3 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
unsigned int V_21 ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_19 = V_15 -> V_22 [ 0 ] ;
V_21 = V_15 -> V_22 [ 1 ] ;
V_3 = NULL ;
if ( V_19 == 0 ) {
V_18 = F_1 ( & V_3 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = F_16 ( V_3 , 0 ) ;
V_21 = F_17 ( V_3 , 0 ) ;
F_18 ( V_2 , & V_3 -> V_2 ) ;
}
V_18 = F_19 ( V_2 , V_19 , 0x20 ) ;
if ( V_18 )
return V_18 ;
V_20 = F_11 ( V_2 ) ;
if ( V_20 < 0 )
return - V_23 ;
V_2 -> V_24 = V_5 + V_20 ;
V_17 = V_2 -> V_24 ;
V_2 -> V_25 = V_17 -> V_26 ;
if ( V_21 != 0 ) {
if ( V_21 > 15 || V_27 [ V_21 ] == - 1 )
return - V_28 ;
V_18 = F_20 ( V_21 , V_29 , 0 ,
V_2 -> V_25 , V_2 ) ;
if ( V_18 < 0 )
return - V_28 ;
V_2 -> V_21 = V_21 ;
}
V_18 = F_21 ( V_2 , V_27 [ V_2 -> V_21 ] , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static void F_22 ( struct V_11 * V_2 )
{
struct V_1 * V_3 ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_3 = V_2 -> V_30 ? F_25 ( V_2 -> V_30 ) : NULL ;
if ( V_3 )
F_8 ( V_3 ) ;
}
