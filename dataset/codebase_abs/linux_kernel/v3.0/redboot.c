static inline int F_1 ( struct V_1 * V_2 )
{
return 1 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * * V_6 ,
unsigned long V_7 )
{
int V_8 = 0 ;
struct V_1 * V_9 ;
struct V_5 * V_10 ;
struct V_11 * V_12 = NULL , * V_13 ;
int V_14 , V_15 ;
T_1 V_16 ;
char * V_17 ;
char * V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 ;
unsigned long V_22 ;
#ifdef F_3
static char V_23 [] = L_1 ;
#endif
if ( V_24 < 0 ) {
V_22 = V_4 -> V_25 + V_24 * V_4 -> V_26 ;
while ( V_4 -> V_27 &&
V_4 -> V_27 ( V_4 , V_22 ) ) {
if ( ! V_22 ) {
V_28:
F_4 ( V_29 L_2 ) ;
return - V_30 ;
}
V_22 -= V_4 -> V_26 ;
}
} else {
V_22 = V_24 * V_4 -> V_26 ;
while ( V_4 -> V_27 &&
V_4 -> V_27 ( V_4 , V_22 ) ) {
V_22 += V_4 -> V_26 ;
if ( V_22 == V_4 -> V_25 )
goto V_28;
}
}
V_9 = F_5 ( V_4 -> V_26 ) ;
if ( ! V_9 )
return - V_31 ;
F_4 ( V_29 L_3 ,
V_4 -> V_32 , V_22 ) ;
V_14 = V_4 -> V_33 ( V_4 , V_22 ,
V_4 -> V_26 , & V_16 , ( void * ) V_9 ) ;
if ( V_14 )
goto V_34;
if ( V_16 != V_4 -> V_26 ) {
V_14 = - V_30 ;
goto V_34;
}
V_21 = ( V_4 -> V_26 / sizeof( struct V_1 ) ) ;
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
if ( ! memcmp ( V_9 [ V_15 ] . V_32 , L_4 , 14 ) ) {
if ( F_6 ( V_9 [ V_15 ] . V_25 ) == V_4 -> V_26 ||
( V_9 [ V_15 ] . V_25 > V_4 -> V_26
&& F_6 ( V_9 [ V_15 ] . V_25 ) < V_4 -> V_26 ) ) {
int V_35 ;
V_21 = F_6 ( V_9 [ V_15 ] . V_25 ) / sizeof ( struct V_1 ) ;
for ( V_35 = 0 ; V_35 < V_21 ; ++ V_35 ) {
if ( V_9 [ V_35 ] . V_32 [ 0 ] == 0xff ) {
if ( V_9 [ V_35 ] . V_32 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
F_7 ( & V_9 [ V_35 ] . V_36 ) ;
F_7 ( & V_9 [ V_35 ] . V_37 ) ;
F_7 ( & V_9 [ V_35 ] . V_25 ) ;
F_7 ( & V_9 [ V_35 ] . V_38 ) ;
F_7 ( & V_9 [ V_35 ] . V_39 ) ;
F_7 ( & V_9 [ V_35 ] . V_40 ) ;
F_7 ( & V_9 [ V_35 ] . V_41 ) ;
}
} else if ( V_9 [ V_15 ] . V_25 < V_4 -> V_26 ) {
V_21 = V_9 [ V_15 ] . V_25 / sizeof( struct V_1 ) ;
}
break;
}
}
if ( V_15 == V_21 ) {
F_4 ( V_29 L_5 ,
V_4 -> V_32 ) ;
V_14 = 0 ;
goto V_34;
}
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
struct V_11 * V_42 , * * V_43 ;
if ( V_9 [ V_15 ] . V_32 [ 0 ] == 0xff ) {
if ( V_9 [ V_15 ] . V_32 [ 1 ] == 0xff ) {
break;
} else {
continue;
}
}
if ( ! F_1 ( & V_9 [ V_15 ] ) )
break;
V_42 = F_8 ( sizeof( struct V_11 ) , V_44 ) ;
V_19 += strlen ( V_9 [ V_15 ] . V_32 ) + 1 ;
if ( ! V_42 ) {
V_14 = - V_31 ;
goto V_34;
}
V_42 -> V_2 = & V_9 [ V_15 ] ;
if ( V_7 ) {
V_9 [ V_15 ] . V_36 -= V_7 ;
} else {
V_9 [ V_15 ] . V_36 &= V_4 -> V_25 - 1 ;
}
V_43 = & V_12 ;
while( * V_43 && ( * V_43 ) -> V_2 -> V_36 < V_42 -> V_2 -> V_36 )
V_43 = & ( * V_43 ) -> V_45 ;
V_42 -> V_45 = * V_43 ;
* V_43 = V_42 ;
V_8 ++ ;
}
#ifdef F_3
if ( V_12 -> V_2 -> V_36 ) {
V_8 ++ ;
V_20 = sizeof( V_23 ) ;
}
for ( V_13 = V_12 ; V_13 -> V_45 ; V_13 = V_13 -> V_45 ) {
if ( V_13 -> V_2 -> V_36 + V_13 -> V_2 -> V_25 + V_4 -> V_26 <= V_13 -> V_45 -> V_2 -> V_36 ) {
V_8 ++ ;
V_20 = sizeof( V_23 ) ;
}
}
#endif
V_10 = F_9 ( sizeof( * V_10 ) * V_8 + V_20 + V_19 , V_44 ) ;
if ( ! V_10 ) {
V_14 = - V_31 ;
goto V_34;
}
V_18 = ( char * ) & V_10 [ V_8 ] ;
#ifdef F_3
if ( V_20 > 0 ) {
strcpy ( V_18 , V_23 ) ;
}
#endif
V_17 = V_18 + V_20 ;
V_15 = 0 ;
#ifdef F_3
if ( V_12 -> V_2 -> V_36 ) {
V_10 [ 0 ] . V_32 = V_18 ;
V_10 [ 0 ] . V_25 = V_12 -> V_2 -> V_36 ;
V_10 [ 0 ] . V_22 = 0 ;
V_15 ++ ;
}
#endif
for ( ; V_15 < V_8 ; V_15 ++ ) {
V_10 [ V_15 ] . V_25 = V_12 -> V_2 -> V_25 ;
V_10 [ V_15 ] . V_22 = V_12 -> V_2 -> V_36 ;
V_10 [ V_15 ] . V_32 = V_17 ;
strcpy ( V_17 , V_12 -> V_2 -> V_32 ) ;
#ifdef F_10
if ( ! memcmp ( V_17 , L_6 , 8 ) ||
! memcmp ( V_17 , L_7 , 15 ) ||
! memcmp ( V_17 , L_4 , 14 ) ) {
V_10 [ V_15 ] . V_46 = V_47 ;
}
#endif
V_17 += strlen ( V_17 ) + 1 ;
#ifdef F_3
if( V_12 -> V_45 && V_12 -> V_2 -> V_36 + V_12 -> V_2 -> V_25 + V_4 -> V_26 <= V_12 -> V_45 -> V_2 -> V_36 ) {
V_15 ++ ;
V_10 [ V_15 ] . V_22 = V_10 [ V_15 - 1 ] . V_25 + V_10 [ V_15 - 1 ] . V_22 ;
V_10 [ V_15 ] . V_25 = V_12 -> V_45 -> V_2 -> V_36 - V_10 [ V_15 ] . V_22 ;
V_10 [ V_15 ] . V_32 = V_18 ;
}
#endif
V_13 = V_12 ;
V_12 = V_12 -> V_45 ;
F_11 ( V_13 ) ;
}
V_14 = V_8 ;
* V_6 = V_10 ;
V_34:
while ( V_12 ) {
struct V_11 * V_48 = V_12 ;
V_12 = V_12 -> V_45 ;
F_11 ( V_48 ) ;
}
F_12 ( V_9 ) ;
return V_14 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( & V_49 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_49 ) ;
}
