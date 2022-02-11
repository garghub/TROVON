static inline int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
struct V_7 * V_8 )
{
int V_9 = 0 ;
struct V_1 * V_10 ;
struct V_5 * V_11 ;
struct V_12 * V_13 = NULL , * V_14 ;
int V_15 , V_16 ;
T_1 V_17 ;
char * V_18 ;
char * V_19 ;
int V_20 = 0 ;
int V_21 = 0 ;
int V_22 ;
unsigned long V_23 ;
#ifdef F_3
static char V_24 [] = L_1 ;
#endif
if ( V_25 < 0 ) {
V_23 = V_4 -> V_26 + V_25 * V_4 -> V_27 ;
while ( F_4 ( V_4 ) &&
F_5 ( V_4 , V_23 ) ) {
if ( ! V_23 ) {
V_28:
F_6 ( V_29 L_2 ) ;
return - V_30 ;
}
V_23 -= V_4 -> V_27 ;
}
} else {
V_23 = V_25 * V_4 -> V_27 ;
while ( F_4 ( V_4 ) &&
F_5 ( V_4 , V_23 ) ) {
V_23 += V_4 -> V_27 ;
if ( V_23 == V_4 -> V_26 )
goto V_28;
}
}
V_10 = F_7 ( V_4 -> V_27 ) ;
if ( ! V_10 )
return - V_31 ;
F_6 ( V_29 L_3 ,
V_4 -> V_32 , V_23 ) ;
V_15 = F_8 ( V_4 , V_23 , V_4 -> V_27 , & V_17 ,
( void * ) V_10 ) ;
if ( V_15 )
goto V_33;
if ( V_17 != V_4 -> V_27 ) {
V_15 = - V_30 ;
goto V_33;
}
V_22 = ( V_4 -> V_27 / sizeof( struct V_1 ) ) ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( ! memcmp ( V_10 [ V_16 ] . V_32 , L_4 , 14 ) ) {
if ( F_9 ( V_10 [ V_16 ] . V_26 ) == V_4 -> V_27 ||
( V_10 [ V_16 ] . V_26 > V_4 -> V_27
&& F_9 ( V_10 [ V_16 ] . V_26 ) < V_4 -> V_27 ) ) {
int V_34 ;
V_22 = F_9 ( V_10 [ V_16 ] . V_26 ) / sizeof ( struct V_1 ) ;
for ( V_34 = 0 ; V_34 < V_22 ; ++ V_34 ) {
if ( V_10 [ V_34 ] . V_32 [ 0 ] == 0xff ) {
if ( V_10 [ V_34 ] . V_32 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
F_10 ( & V_10 [ V_34 ] . V_35 ) ;
F_10 ( & V_10 [ V_34 ] . V_36 ) ;
F_10 ( & V_10 [ V_34 ] . V_26 ) ;
F_10 ( & V_10 [ V_34 ] . V_37 ) ;
F_10 ( & V_10 [ V_34 ] . V_38 ) ;
F_10 ( & V_10 [ V_34 ] . V_39 ) ;
F_10 ( & V_10 [ V_34 ] . V_40 ) ;
}
} else if ( V_10 [ V_16 ] . V_26 < V_4 -> V_27 ) {
V_22 = V_10 [ V_16 ] . V_26 / sizeof( struct V_1 ) ;
}
break;
}
}
if ( V_16 == V_22 ) {
F_6 ( V_29 L_5 ,
V_4 -> V_32 ) ;
V_15 = 0 ;
goto V_33;
}
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
struct V_12 * V_41 , * * V_42 ;
if ( V_10 [ V_16 ] . V_32 [ 0 ] == 0xff ) {
if ( V_10 [ V_16 ] . V_32 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
if ( ! F_1 ( & V_10 [ V_16 ] ) )
break;
V_41 = F_11 ( sizeof( struct V_12 ) , V_43 ) ;
V_20 += strlen ( V_10 [ V_16 ] . V_32 ) + 1 ;
if ( ! V_41 ) {
V_15 = - V_31 ;
goto V_33;
}
V_41 -> V_2 = & V_10 [ V_16 ] ;
if ( V_8 && V_8 -> V_44 )
V_10 [ V_16 ] . V_35 -= V_8 -> V_44 ;
else
V_10 [ V_16 ] . V_35 &= V_4 -> V_26 - 1 ;
V_42 = & V_13 ;
while( * V_42 && ( * V_42 ) -> V_2 -> V_35 < V_41 -> V_2 -> V_35 )
V_42 = & ( * V_42 ) -> V_45 ;
V_41 -> V_45 = * V_42 ;
* V_42 = V_41 ;
V_9 ++ ;
}
#ifdef F_3
if ( V_13 -> V_2 -> V_35 ) {
V_9 ++ ;
V_21 = sizeof( V_24 ) ;
}
for ( V_14 = V_13 ; V_14 -> V_45 ; V_14 = V_14 -> V_45 ) {
if ( V_14 -> V_2 -> V_35 + V_14 -> V_2 -> V_26 + V_4 -> V_27 <= V_14 -> V_45 -> V_2 -> V_35 ) {
V_9 ++ ;
V_21 = sizeof( V_24 ) ;
}
}
#endif
V_11 = F_12 ( sizeof( * V_11 ) * V_9 + V_21 + V_20 , V_43 ) ;
if ( ! V_11 ) {
V_15 = - V_31 ;
goto V_33;
}
V_19 = ( char * ) & V_11 [ V_9 ] ;
#ifdef F_3
if ( V_21 > 0 ) {
strcpy ( V_19 , V_24 ) ;
}
#endif
V_18 = V_19 + V_21 ;
V_16 = 0 ;
#ifdef F_3
if ( V_13 -> V_2 -> V_35 ) {
V_11 [ 0 ] . V_32 = V_19 ;
V_11 [ 0 ] . V_26 = V_13 -> V_2 -> V_35 ;
V_11 [ 0 ] . V_23 = 0 ;
V_16 ++ ;
}
#endif
for ( ; V_16 < V_9 ; V_16 ++ ) {
V_11 [ V_16 ] . V_26 = V_13 -> V_2 -> V_26 ;
V_11 [ V_16 ] . V_23 = V_13 -> V_2 -> V_35 ;
V_11 [ V_16 ] . V_32 = V_18 ;
strcpy ( V_18 , V_13 -> V_2 -> V_32 ) ;
#ifdef F_13
if ( ! memcmp ( V_18 , L_6 , 8 ) ||
! memcmp ( V_18 , L_7 , 15 ) ||
! memcmp ( V_18 , L_4 , 14 ) ) {
V_11 [ V_16 ] . V_46 = V_47 ;
}
#endif
V_18 += strlen ( V_18 ) + 1 ;
#ifdef F_3
if( V_13 -> V_45 && V_13 -> V_2 -> V_35 + V_13 -> V_2 -> V_26 + V_4 -> V_27 <= V_13 -> V_45 -> V_2 -> V_35 ) {
V_16 ++ ;
V_11 [ V_16 ] . V_23 = V_11 [ V_16 - 1 ] . V_26 + V_11 [ V_16 - 1 ] . V_23 ;
V_11 [ V_16 ] . V_26 = V_13 -> V_45 -> V_2 -> V_35 - V_11 [ V_16 ] . V_23 ;
V_11 [ V_16 ] . V_32 = V_19 ;
}
#endif
V_14 = V_13 ;
V_13 = V_13 -> V_45 ;
F_14 ( V_14 ) ;
}
V_15 = V_9 ;
* V_6 = V_11 ;
V_33:
while ( V_13 ) {
struct V_12 * V_48 = V_13 ;
V_13 = V_13 -> V_45 ;
F_14 ( V_48 ) ;
}
F_15 ( V_10 ) ;
return V_15 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_49 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_49 ) ;
}
