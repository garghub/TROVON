static struct V_1 T_1 F_1 ( void )
{
long V_2 = 0 ;
char * V_3 ;
void * V_4 ;
T_2 V_5 ;
#ifdef F_2
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) F_3 ( & V_6 ) ;
V_3 = ( char * ) F_3 ( V_8 ) ;
V_4 = ( void * ) V_7 -> V_9 . V_10 ;
V_5 = V_7 -> V_9 . V_11 ;
#else
V_3 = V_8 ;
V_4 = ( void * ) ( V_6 . V_9 . V_10 + V_12 ) ;
V_5 = V_6 . V_9 . V_11 ;
#endif
return F_4 ( V_3 , V_4 , V_5 , & V_2 ) ;
}
static T_2 F_5 ( T_3 * V_13 , T_4 V_14 )
{
T_2 V_5 = 0 ;
T_4 * V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_16 ||
V_15 [ 1 ] != V_17 ||
V_15 [ 2 ] == 0 )
return V_5 ;
V_5 = V_15 [ 2 ] + V_18 ;
V_14 -= V_5 ;
V_13 += V_5 ;
while ( V_14 ) {
T_5 V_19 ;
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_20 )
break;
V_19 = V_15 [ 1 ] ;
if ( V_19 > V_21 )
break;
V_5 += V_19 + V_22 ;
V_13 += V_19 + V_22 ;
V_14 -= V_19 + V_22 ;
}
return V_5 ;
}
static void F_6 ( void * V_23 , T_2 V_5 )
{
struct V_24 * V_25 ;
T_2 * V_26 ;
T_4 * V_15 ;
T_3 * V_13 , * * V_27 ;
T_5 V_28 = 0 ;
int V_2 , V_29 ;
T_4 V_30 , V_31 , V_32 , V_33 , V_34 ;
T_4 * V_35 ;
#ifdef F_2
V_35 = ( T_4 * ) F_3 ( & V_36 ) ;
V_26 = ( T_2 * ) F_3 ( & V_37 ) ;
V_27 = ( T_3 * * ) F_3 ( & V_38 ) ;
#else
V_35 = & V_36 ;
V_26 = & V_37 ;
V_27 = & V_38 ;
#endif
V_13 = V_23 ;
V_29 = V_5 ;
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_16 ||
V_15 [ 1 ] != V_17 ||
V_15 [ 2 ] == 0 )
return;
V_31 = 0x00000001 ;
V_33 = 0 ;
F_7 ( & V_31 , & V_32 , & V_33 , & V_34 ) ;
while ( V_29 > 0 ) {
V_25 = (struct V_24 * ) ( V_13 + V_18 ) ;
* V_27 = V_13 ;
V_2 = V_15 [ 2 ] + V_18 ;
V_13 += V_2 ;
V_29 -= V_2 ;
V_28 = F_8 ( V_25 , V_31 ) ;
if ( V_28 ) {
V_39 = V_28 ;
* V_26 = F_5 ( * V_27 , V_29 + V_2 ) ;
V_29 = * V_26 - V_2 ;
break;
}
while ( V_29 > 0 ) {
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] == V_16 &&
V_15 [ 1 ] == V_17 )
break;
V_2 = V_15 [ 1 ] + V_22 ;
V_13 += V_2 ;
V_29 -= V_2 ;
}
V_2 = V_13 - ( T_3 * ) V_23 ;
V_23 = V_13 ;
}
if ( ! V_28 ) {
* V_27 = NULL ;
* V_26 = 0 ;
return;
}
F_9 ( V_40 , V_30 , V_31 ) ;
while ( V_29 > 0 ) {
struct V_41 * V_42 ;
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_20 ||
V_15 [ 1 ] == 0 )
break;
V_42 = (struct V_41 * ) ( V_13 + V_22 ) ;
if ( V_28 == V_42 -> V_9 . V_43 && V_30 < V_42 -> V_9 . V_44 ) {
if ( ! F_10 ( V_42 ) ) {
V_30 = V_42 -> V_9 . V_44 ;
* V_35 = V_30 ;
memcpy ( V_45 , V_42 ,
F_11 ( T_4 , V_15 [ 1 ] , V_21 ) ) ;
}
}
V_2 = V_15 [ 1 ] + V_22 ;
V_13 += V_2 ;
V_29 -= V_2 ;
}
}
void T_1 F_12 ( void )
{
struct V_1 V_46 ;
void * * V_13 ;
T_2 * V_5 ;
#ifdef F_2
V_13 = ( void * * ) F_3 ( & V_47 . V_13 ) ;
V_5 = ( T_2 * ) F_3 ( & V_47 . V_5 ) ;
#else
V_13 = & V_47 . V_13 ;
V_5 = & V_47 . V_5 ;
#endif
V_46 = F_1 () ;
if ( ! V_46 . V_13 )
return;
* V_13 = V_46 . V_13 ;
* V_5 = V_46 . V_5 ;
F_6 ( V_46 . V_13 , V_46 . V_5 ) ;
}
void F_13 ( void )
{
struct V_41 * V_42 ;
T_2 * V_48 ;
void * * V_23 ;
V_42 = (struct V_41 * ) F_14 ( V_45 ) ;
if ( V_42 -> V_9 . V_44 && V_42 -> V_9 . V_43 ) {
F_10 ( V_42 ) ;
return;
}
V_23 = ( void * ) F_3 ( & V_38 ) ;
V_48 = ( T_2 * ) F_3 ( & V_37 ) ;
if ( ! * V_23 || ! * V_48 )
return;
F_6 ( * V_23 , * V_48 ) ;
}
static void T_1 F_15 ( void * V_49 )
{
unsigned int V_50 = F_16 () ;
struct V_51 * V_52 = V_51 + V_50 ;
V_52 -> V_53 . V_54 = F_17 ( 0x00000001 ) ;
}
static void T_1 F_18 ( void )
{
unsigned int V_55 = V_56 . V_57 ;
struct V_51 * V_52 = V_51 + V_55 ;
if ( ! V_52 -> V_53 . V_54 )
F_19 ( V_55 , F_15 , NULL , 1 ) ;
}
void F_13 ( void )
{
unsigned int V_50 = F_16 () ;
struct V_51 * V_52 = V_51 + V_50 ;
struct V_24 * V_25 ;
struct V_41 * V_42 ;
T_4 V_30 , V_31 ;
T_5 V_28 ;
if ( ! V_50 )
return;
if ( ! V_38 )
return;
F_20 ( V_40 , V_30 , V_31 ) ;
V_52 -> V_53 . V_30 = V_30 ;
V_52 -> V_53 . V_54 = V_31 ;
V_31 = F_17 ( 0x00000001 ) ;
V_25 = (struct V_24 * ) ( V_38 + V_18 ) ;
V_28 = F_8 ( V_25 , V_31 ) ;
if ( ! V_28 )
return;
if ( V_28 == V_39 ) {
V_42 = (struct V_41 * ) V_45 ;
if ( V_42 && V_30 < V_42 -> V_9 . V_44 ) {
if ( ! F_10 ( V_42 ) )
V_36 = V_42 -> V_9 . V_44 ;
}
} else {
if ( ! V_47 . V_13 )
return;
F_6 ( V_47 . V_13 , V_47 . V_5 ) ;
}
}
int T_1 F_21 ( void )
{
unsigned long V_27 ;
enum V_58 V_59 ;
T_4 V_31 ;
if ( ! V_38 )
return - V_60 ;
#ifdef F_2
F_18 () ;
V_27 = ( unsigned long ) V_38 ;
#else
V_27 = F_14 ( V_38 ) ;
#endif
if ( V_61 )
V_38 = ( T_3 * ) ( F_22 ( V_61 ) +
( V_27 - V_6 . V_9 . V_10 ) ) ;
if ( V_36 )
F_23 ( L_1 ,
V_36 ) ;
V_31 = F_17 ( 0x00000001 ) ;
V_31 = ( ( V_31 >> 8 ) & 0xf ) + ( ( V_31 >> 20 ) & 0xff ) ;
V_59 = F_24 ( V_31 , V_38 , V_37 ) ;
if ( V_59 != V_62 )
return - V_60 ;
V_38 = NULL ;
V_37 = 0 ;
return 0 ;
}
