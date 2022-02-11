static int F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = NULL ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = F_3 ( NULL ,
F_4 ( 'N' , 'I' , 'C' ) ,
F_5 ( V_5 [ V_4 ] .
V_6 ) , NULL ) ;
if ( ! V_3 || ! V_3 -> V_7 )
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
static const struct V_11 * F_11 ( struct V_12 * V_2 )
{
int V_13 = F_12 ( V_2 , 511 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
const struct V_11 * V_14 = & V_5 [ V_4 ] ;
if ( V_14 -> V_13 == V_13 )
return V_14 ;
}
if ( V_13 == 255 )
F_13 ( V_2 -> V_15 , L_1 ) ;
else if ( V_13 == 0 )
F_13 ( V_2 -> V_15 ,
L_2 ) ;
else
F_13 ( V_2 -> V_15 ,
L_3 , V_13 ) ;
return NULL ;
}
static int F_14 ( struct V_12 * V_2 ,
struct V_16 * V_17 )
{
const struct V_11 * V_14 ;
struct V_1 * V_3 ;
int V_18 ;
unsigned long V_19 ;
unsigned int V_20 ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_19 = V_17 -> V_21 [ 0 ] ;
V_20 = V_17 -> V_21 [ 1 ] ;
V_3 = NULL ;
if ( V_19 == 0 ) {
V_18 = F_1 ( & V_3 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = F_16 ( V_3 , 0 ) ;
V_20 = F_17 ( V_3 , 0 ) ;
F_18 ( V_2 , & V_3 -> V_2 ) ;
}
V_18 = F_19 ( V_2 , V_19 , 0x20 ) ;
if ( V_18 )
return V_18 ;
V_14 = F_11 ( V_2 ) ;
if ( ! V_14 )
return - V_10 ;
V_2 -> V_22 = V_14 ;
V_2 -> V_23 = V_14 -> V_24 ;
if ( V_20 != 0 ) {
if ( V_20 > 15 || V_25 [ V_20 ] == - 1 )
return - V_26 ;
V_18 = F_20 ( V_20 , V_27 , 0 ,
V_2 -> V_23 , V_2 ) ;
if ( V_18 < 0 )
return - V_26 ;
V_2 -> V_20 = V_20 ;
}
V_18 = F_21 ( V_2 , V_25 [ V_2 -> V_20 ] , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static void F_22 ( struct V_12 * V_2 )
{
struct V_1 * V_3 ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_3 = V_2 -> V_28 ? F_25 ( V_2 -> V_28 ) : NULL ;
if ( V_3 )
F_8 ( V_3 ) ;
}
