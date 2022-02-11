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
while ( V_4 -> V_28 &&
V_4 -> V_28 ( V_4 , V_23 ) ) {
if ( ! V_23 ) {
V_29:
F_4 ( V_30 L_2 ) ;
return - V_31 ;
}
V_23 -= V_4 -> V_27 ;
}
} else {
V_23 = V_25 * V_4 -> V_27 ;
while ( V_4 -> V_28 &&
V_4 -> V_28 ( V_4 , V_23 ) ) {
V_23 += V_4 -> V_27 ;
if ( V_23 == V_4 -> V_26 )
goto V_29;
}
}
V_10 = F_5 ( V_4 -> V_27 ) ;
if ( ! V_10 )
return - V_32 ;
F_4 ( V_30 L_3 ,
V_4 -> V_33 , V_23 ) ;
V_15 = V_4 -> V_34 ( V_4 , V_23 ,
V_4 -> V_27 , & V_17 , ( void * ) V_10 ) ;
if ( V_15 )
goto V_35;
if ( V_17 != V_4 -> V_27 ) {
V_15 = - V_31 ;
goto V_35;
}
V_22 = ( V_4 -> V_27 / sizeof( struct V_1 ) ) ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( ! memcmp ( V_10 [ V_16 ] . V_33 , L_4 , 14 ) ) {
if ( F_6 ( V_10 [ V_16 ] . V_26 ) == V_4 -> V_27 ||
( V_10 [ V_16 ] . V_26 > V_4 -> V_27
&& F_6 ( V_10 [ V_16 ] . V_26 ) < V_4 -> V_27 ) ) {
int V_36 ;
V_22 = F_6 ( V_10 [ V_16 ] . V_26 ) / sizeof ( struct V_1 ) ;
for ( V_36 = 0 ; V_36 < V_22 ; ++ V_36 ) {
if ( V_10 [ V_36 ] . V_33 [ 0 ] == 0xff ) {
if ( V_10 [ V_36 ] . V_33 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
F_7 ( & V_10 [ V_36 ] . V_37 ) ;
F_7 ( & V_10 [ V_36 ] . V_38 ) ;
F_7 ( & V_10 [ V_36 ] . V_26 ) ;
F_7 ( & V_10 [ V_36 ] . V_39 ) ;
F_7 ( & V_10 [ V_36 ] . V_40 ) ;
F_7 ( & V_10 [ V_36 ] . V_41 ) ;
F_7 ( & V_10 [ V_36 ] . V_42 ) ;
}
} else if ( V_10 [ V_16 ] . V_26 < V_4 -> V_27 ) {
V_22 = V_10 [ V_16 ] . V_26 / sizeof( struct V_1 ) ;
}
break;
}
}
if ( V_16 == V_22 ) {
F_4 ( V_30 L_5 ,
V_4 -> V_33 ) ;
V_15 = 0 ;
goto V_35;
}
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
struct V_12 * V_43 , * * V_44 ;
if ( V_10 [ V_16 ] . V_33 [ 0 ] == 0xff ) {
if ( V_10 [ V_16 ] . V_33 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
if ( ! F_1 ( & V_10 [ V_16 ] ) )
break;
V_43 = F_8 ( sizeof( struct V_12 ) , V_45 ) ;
V_20 += strlen ( V_10 [ V_16 ] . V_33 ) + 1 ;
if ( ! V_43 ) {
V_15 = - V_32 ;
goto V_35;
}
V_43 -> V_2 = & V_10 [ V_16 ] ;
if ( V_8 && V_8 -> V_46 )
V_10 [ V_16 ] . V_37 -= V_8 -> V_46 ;
else
V_10 [ V_16 ] . V_37 &= V_4 -> V_26 - 1 ;
V_44 = & V_13 ;
while( * V_44 && ( * V_44 ) -> V_2 -> V_37 < V_43 -> V_2 -> V_37 )
V_44 = & ( * V_44 ) -> V_47 ;
V_43 -> V_47 = * V_44 ;
* V_44 = V_43 ;
V_9 ++ ;
}
#ifdef F_3
if ( V_13 -> V_2 -> V_37 ) {
V_9 ++ ;
V_21 = sizeof( V_24 ) ;
}
for ( V_14 = V_13 ; V_14 -> V_47 ; V_14 = V_14 -> V_47 ) {
if ( V_14 -> V_2 -> V_37 + V_14 -> V_2 -> V_26 + V_4 -> V_27 <= V_14 -> V_47 -> V_2 -> V_37 ) {
V_9 ++ ;
V_21 = sizeof( V_24 ) ;
}
}
#endif
V_11 = F_9 ( sizeof( * V_11 ) * V_9 + V_21 + V_20 , V_45 ) ;
if ( ! V_11 ) {
V_15 = - V_32 ;
goto V_35;
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
if ( V_13 -> V_2 -> V_37 ) {
V_11 [ 0 ] . V_33 = V_19 ;
V_11 [ 0 ] . V_26 = V_13 -> V_2 -> V_37 ;
V_11 [ 0 ] . V_23 = 0 ;
V_16 ++ ;
}
#endif
for ( ; V_16 < V_9 ; V_16 ++ ) {
V_11 [ V_16 ] . V_26 = V_13 -> V_2 -> V_26 ;
V_11 [ V_16 ] . V_23 = V_13 -> V_2 -> V_37 ;
V_11 [ V_16 ] . V_33 = V_18 ;
strcpy ( V_18 , V_13 -> V_2 -> V_33 ) ;
#ifdef F_10
if ( ! memcmp ( V_18 , L_6 , 8 ) ||
! memcmp ( V_18 , L_7 , 15 ) ||
! memcmp ( V_18 , L_4 , 14 ) ) {
V_11 [ V_16 ] . V_48 = V_49 ;
}
#endif
V_18 += strlen ( V_18 ) + 1 ;
#ifdef F_3
if( V_13 -> V_47 && V_13 -> V_2 -> V_37 + V_13 -> V_2 -> V_26 + V_4 -> V_27 <= V_13 -> V_47 -> V_2 -> V_37 ) {
V_16 ++ ;
V_11 [ V_16 ] . V_23 = V_11 [ V_16 - 1 ] . V_26 + V_11 [ V_16 - 1 ] . V_23 ;
V_11 [ V_16 ] . V_26 = V_13 -> V_47 -> V_2 -> V_37 - V_11 [ V_16 ] . V_23 ;
V_11 [ V_16 ] . V_33 = V_19 ;
}
#endif
V_14 = V_13 ;
V_13 = V_13 -> V_47 ;
F_11 ( V_14 ) ;
}
V_15 = V_9 ;
* V_6 = V_11 ;
V_35:
while ( V_13 ) {
struct V_12 * V_50 = V_13 ;
V_13 = V_13 -> V_47 ;
F_11 ( V_50 ) ;
}
F_12 ( V_10 ) ;
return V_15 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_51 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_51 ) ;
}
