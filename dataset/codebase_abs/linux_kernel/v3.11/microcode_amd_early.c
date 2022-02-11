static struct V_1 T_1 F_1 ( void )
{
long V_2 = 0 ;
char * V_3 ;
void * V_4 ;
T_2 V_5 ;
unsigned long * V_6 ;
T_2 * V_7 ;
struct V_1 V_8 ;
#ifdef F_2
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) F_3 ( & V_9 ) ;
V_3 = ( char * ) F_3 ( V_11 ) ;
V_4 = ( void * ) V_10 -> V_12 . V_13 ;
V_5 = V_10 -> V_12 . V_14 ;
V_6 = ( unsigned long * ) F_3 ( & V_15 ) ;
V_7 = ( T_2 * ) F_3 ( & V_16 ) ;
#else
V_3 = V_11 ;
V_4 = ( void * ) ( V_9 . V_12 . V_13 + V_17 ) ;
V_5 = V_9 . V_12 . V_14 ;
V_6 = & V_15 ;
V_7 = & V_16 ;
#endif
V_8 = F_4 ( V_3 , V_4 , V_5 , & V_2 ) ;
if ( ! V_8 . V_18 )
return V_8 ;
if ( * ( V_19 * ) V_8 . V_18 != V_20 ) {
V_8 . V_18 = NULL ;
V_8 . V_5 = 0 ;
return V_8 ;
}
* V_6 = ( V_21 * ) V_8 . V_18 - ( V_21 * ) V_4 ;
* V_7 = V_8 . V_5 ;
return V_8 ;
}
static void F_5 ( void * V_22 , T_2 V_5 )
{
struct V_23 * V_24 ;
V_19 * V_25 ;
V_21 * V_18 ;
T_3 V_26 = 0 ;
int V_2 , V_27 ;
V_19 V_28 , V_29 ;
V_19 * V_30 ;
unsigned long * V_6 ;
T_2 * V_7 ;
#ifdef F_2
V_30 = ( V_19 * ) F_3 ( & V_31 ) ;
V_6 = ( unsigned long * ) F_3 ( & V_15 ) ;
V_7 = ( T_2 * ) F_3 ( & V_16 ) ;
#else
V_30 = & V_31 ;
V_6 = & V_15 ;
V_7 = & V_16 ;
#endif
V_18 = V_22 ;
V_27 = V_5 ;
V_25 = ( V_19 * ) V_18 ;
if ( V_25 [ 1 ] != V_32 ||
V_25 [ 2 ] == 0 )
return;
V_29 = F_6 ( 0x00000001 ) ;
while ( V_27 > 0 ) {
V_24 = (struct V_23 * ) ( V_18 + V_33 ) ;
V_2 = V_25 [ 2 ] + V_33 ;
V_18 += V_2 ;
V_27 -= V_2 ;
V_26 = F_7 ( V_24 , V_29 ) ;
if ( V_26 )
break;
while ( V_27 > 0 ) {
V_25 = ( V_19 * ) V_18 ;
if ( V_25 [ 0 ] == V_20 &&
V_25 [ 1 ] == V_32 )
break;
V_2 = V_25 [ 1 ] + V_34 ;
V_18 += V_2 ;
V_27 -= V_2 ;
}
V_2 = V_18 - ( V_21 * ) V_22 ;
* V_6 += V_2 ;
* V_7 -= V_2 ;
V_22 = V_18 ;
}
if ( ! V_26 ) {
* V_7 = 0 ;
return;
}
F_8 ( V_35 , V_28 , V_29 ) ;
while ( V_27 > 0 ) {
struct V_36 * V_37 ;
V_25 = ( V_19 * ) V_18 ;
if ( V_25 [ 0 ] != V_38 ||
V_25 [ 1 ] == 0 )
break;
V_37 = (struct V_36 * ) ( V_18 + V_34 ) ;
if ( V_26 == V_37 -> V_12 . V_39 && V_28 < V_37 -> V_12 . V_40 )
if ( F_9 ( V_37 ) == 0 ) {
V_28 = V_37 -> V_12 . V_40 ;
* V_30 = V_28 ;
}
V_2 = V_25 [ 1 ] + V_34 ;
V_18 += V_2 ;
V_27 -= V_2 ;
}
V_2 = * V_7 - ( V_18 - ( V_21 * ) V_22 ) ;
* V_7 -= V_2 ;
if ( ! ( * V_30 ) )
* V_7 = 0 ;
}
void T_1 F_10 ( void )
{
struct V_1 V_8 = F_1 () ;
if ( ! V_8 . V_18 )
return;
F_5 ( V_8 . V_18 , V_8 . V_5 ) ;
}
void F_11 ( void )
{
struct V_36 * V_37 ;
unsigned long * V_41 ;
unsigned long * V_6 ;
T_2 * V_7 ;
void * V_22 ;
V_37 = (struct V_36 * ) F_12 ( V_42 ) ;
if ( V_37 -> V_12 . V_40 && V_37 -> V_12 . V_39 ) {
F_9 ( V_37 ) ;
return;
}
V_41 = ( unsigned long * ) F_12 ( & V_43 ) ;
V_6 = ( unsigned long * ) F_12 ( & V_15 ) ;
V_7 = ( T_2 * ) F_12 ( & V_16 ) ;
if ( ! * V_7 || ! * V_41 )
return;
V_22 = ( void * ) ( ( unsigned long ) F_12 ( * V_41 ) + * V_6 ) ;
F_5 ( V_22 , * V_7 ) ;
}
static void T_1 F_13 ( void * V_44 )
{
unsigned int V_45 = F_14 () ;
struct V_46 * V_47 = V_46 + V_45 ;
V_47 -> V_48 . V_49 = F_6 ( 0x00000001 ) ;
}
void F_11 ( void )
{
unsigned int V_45 = F_14 () ;
struct V_46 * V_47 = V_46 + V_45 ;
V_19 V_28 , V_29 ;
F_8 ( V_35 , V_28 , V_29 ) ;
V_29 = F_6 ( 0x00000001 ) ;
V_47 -> V_48 . V_28 = V_28 ;
V_47 -> V_48 . V_49 = V_29 ;
if ( V_45 && ! V_50 ) {
void * V_22 ;
if ( ! V_16 || ! V_43 )
return;
V_22 = ( void * ) ( V_43 + V_15 ) ;
V_29 = ( ( V_29 >> 8 ) & 0xf ) + ( ( V_29 >> 20 ) & 0xff ) ;
if ( F_15 ( V_29 , V_22 , V_16 ) != V_51 )
return;
V_50 = true ;
}
F_16 ( V_45 ) ;
}
int T_1 F_17 ( void )
{
enum V_52 V_53 ;
void * V_22 ;
V_19 V_29 ;
#ifdef F_2
unsigned int V_54 = V_55 . V_56 ;
struct V_46 * V_47 = V_46 + V_54 ;
if ( ! V_47 -> V_48 . V_49 )
F_18 ( V_54 , F_13 , NULL , 1 ) ;
#endif
if ( V_31 )
F_19 ( L_1 ,
V_31 ) ;
if ( V_50 || ! V_16 || ! V_43 )
return 0 ;
V_22 = ( void * ) ( V_43 + V_15 ) ;
V_29 = F_6 ( 0x00000001 ) ;
V_29 = ( ( V_29 >> 8 ) & 0xf ) + ( ( V_29 >> 20 ) & 0xff ) ;
V_53 = F_15 ( V_29 , V_22 , V_16 ) ;
if ( V_53 != V_51 )
return - V_57 ;
V_50 = true ;
return 0 ;
}
