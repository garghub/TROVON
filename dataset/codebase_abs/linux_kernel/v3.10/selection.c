static unsigned char F_1 ( int V_1 )
{
return F_2 ( V_2 ,
F_3 ( V_2 , V_1 ) , 0 ) ;
}
void F_4 ( void )
{
V_3 = - 1 ;
}
static int F_5 ( const int V_4 , int V_5 )
{
return ! ( V_4 % V_5 ) || ! ( ( V_4 + 2 ) % V_5 ) ;
}
static unsigned short F_6 ( const unsigned short V_6 , const unsigned short V_7 )
{
return ( V_6 > V_7 ) ? V_7 : V_6 ;
}
int F_7 ( struct V_8 * V_9 )
{
int V_10 , V_11 ;
char * V_12 , * V_13 ;
int V_14 , V_15 , V_16 ;
struct V_17 * V_18 = V_19 [ V_20 ] . V_21 ;
V_22 = F_6 ( V_22 , V_18 -> V_23 - 1 ) ;
V_24 = F_6 ( V_24 , V_18 -> V_25 - 1 ) ;
V_26 = F_6 ( V_26 , V_18 -> V_23 - 1 ) ;
V_27 = F_6 ( V_27 , V_18 -> V_25 - 1 ) ;
V_15 = V_24 * V_18 -> V_28 + ( V_22 << 1 ) ;
V_16 = V_27 * V_18 -> V_28 + ( V_26 << 1 ) ;
if ( V_15 > V_16 ) {
int V_29 = V_15 ;
V_15 = V_16 ;
V_16 = V_29 ;
}
if ( V_2 != V_19 [ V_20 ] . V_21 ) {
F_4 () ;
V_2 = V_19 [ V_20 ] . V_21 ;
F_8 ( V_9 -> V_30 ,
L_1 ) ;
return - V_31 ;
}
V_10 = V_15 ;
V_11 = V_16 ;
if ( V_11 > V_10 &&
! F_5 ( V_11 , V_18 -> V_28 ) &&
F_9 ( F_1 ( V_11 ) ) ) {
for ( V_16 = V_11 + 2 ; ; V_16 += 2 )
if ( ! F_9 ( F_1 ( V_16 ) ) ||
F_5 ( V_16 , V_18 -> V_28 ) )
break;
if ( F_9 ( F_1 ( V_16 ) ) )
V_11 = V_16 ;
}
if ( ( V_10 == V_3 ) && ( V_11 == V_32 ) )
return 0 ;
V_3 = V_10 ;
V_32 = V_11 ;
V_12 = F_10 ( ( V_32 - V_3 ) / 2 + 1 , V_33 ) ;
if ( ! V_12 ) {
F_4 () ;
return - V_34 ;
}
F_11 ( V_35 ) ;
V_35 = V_12 ;
V_13 = V_12 ;
for ( V_14 = V_3 ; V_14 <= V_32 ; V_14 += 2 ) {
* V_12 = F_1 ( V_14 ) ;
if ( ! F_9 ( * V_12 ++ ) )
V_13 = V_12 ;
if ( ! ( ( V_14 + 2 ) % V_18 -> V_28 ) ) {
if ( V_13 != V_12 ) {
V_12 = V_13 ;
* V_12 ++ = '\r' ;
}
V_13 = V_12 ;
}
}
V_36 = V_12 - V_35 ;
return 0 ;
}
int F_12 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = (struct V_17 * ) V_9 -> V_37 ;
int V_38 = 0 , V_39 ;
F_13 ( V_40 , V_41 ) ;
F_14 ( & V_18 -> V_42 , & V_40 ) ;
while ( V_35 && V_36 > V_38 ) {
F_15 ( V_43 ) ;
if ( F_16 ( V_44 , & V_9 -> V_45 ) ) {
if ( F_17 () )
break;
F_18 () ;
continue;
}
V_39 = V_36 - V_38 ;
V_39 = F_19 ( int , V_39 , V_9 -> V_46 ) ;
V_9 -> V_47 -> V_48 -> V_49 ( V_9 , V_35 + V_38 ,
NULL , V_39 ) ;
V_38 += V_39 ;
}
F_20 ( & V_18 -> V_42 , & V_40 ) ;
V_41 -> V_50 = V_51 ;
return 0 ;
}
