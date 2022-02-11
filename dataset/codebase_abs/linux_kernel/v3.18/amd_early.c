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
static void F_6 ( void * V_23 , T_2 V_5 , bool V_24 )
{
struct V_25 * V_26 ;
T_2 * V_27 ;
T_4 * V_15 ;
T_3 * V_13 , * * V_28 ;
T_3 ( * V_29 ) [ V_21 ] ;
T_5 V_30 = 0 ;
int V_2 , V_31 ;
T_4 V_32 , V_33 , V_34 , V_35 , V_36 ;
T_4 * V_37 ;
#ifdef F_2
V_37 = ( T_4 * ) F_3 ( & V_38 ) ;
V_27 = ( T_2 * ) F_3 ( & V_39 ) ;
V_28 = ( T_3 * * ) F_3 ( & V_40 ) ;
V_29 = ( T_3 ( * ) [ V_21 ] ) F_3 ( & V_41 ) ;
#else
V_37 = & V_38 ;
V_27 = & V_39 ;
V_28 = & V_40 ;
V_29 = & V_41 ;
#endif
V_13 = V_23 ;
V_31 = V_5 ;
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_16 ||
V_15 [ 1 ] != V_17 ||
V_15 [ 2 ] == 0 )
return;
V_33 = 0x00000001 ;
V_35 = 0 ;
F_7 ( & V_33 , & V_34 , & V_35 , & V_36 ) ;
while ( V_31 > 0 ) {
V_26 = (struct V_25 * ) ( V_13 + V_18 ) ;
* V_28 = V_13 ;
V_2 = V_15 [ 2 ] + V_18 ;
V_13 += V_2 ;
V_31 -= V_2 ;
V_30 = F_8 ( V_26 , V_33 ) ;
if ( V_30 ) {
V_42 = V_30 ;
* V_27 = F_5 ( * V_28 , V_31 + V_2 ) ;
V_31 = * V_27 - V_2 ;
break;
}
while ( V_31 > 0 ) {
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] == V_16 &&
V_15 [ 1 ] == V_17 )
break;
V_2 = V_15 [ 1 ] + V_22 ;
V_13 += V_2 ;
V_31 -= V_2 ;
}
V_2 = V_13 - ( T_3 * ) V_23 ;
V_23 = V_13 ;
}
if ( ! V_30 ) {
* V_28 = NULL ;
* V_27 = 0 ;
return;
}
F_9 ( V_43 , V_32 , V_33 ) ;
while ( V_31 > 0 ) {
struct V_44 * V_45 ;
V_15 = ( T_4 * ) V_13 ;
if ( V_15 [ 0 ] != V_20 ||
V_15 [ 1 ] == 0 )
break;
V_45 = (struct V_44 * ) ( V_13 + V_22 ) ;
if ( V_30 == V_45 -> V_9 . V_46 && V_32 < V_45 -> V_9 . V_47 ) {
if ( ! F_10 ( V_45 ) ) {
V_32 = V_45 -> V_9 . V_47 ;
* V_37 = V_32 ;
if ( V_24 )
memcpy ( V_29 , V_45 ,
F_11 ( T_4 , V_15 [ 1 ] , V_21 ) ) ;
}
}
V_2 = V_15 [ 1 ] + V_22 ;
V_13 += V_2 ;
V_31 -= V_2 ;
}
}
void T_1 F_12 ( void )
{
struct V_1 V_48 ;
void * * V_13 ;
T_2 * V_5 ;
#ifdef F_2
V_13 = ( void * * ) F_3 ( & V_49 . V_13 ) ;
V_5 = ( T_2 * ) F_3 ( & V_49 . V_5 ) ;
#else
V_13 = & V_49 . V_13 ;
V_5 = & V_49 . V_5 ;
#endif
V_48 = F_1 () ;
if ( ! V_48 . V_13 )
return;
* V_13 = V_48 . V_13 ;
* V_5 = V_48 . V_5 ;
F_6 ( V_48 . V_13 , V_48 . V_5 , true ) ;
}
void F_13 ( void )
{
struct V_44 * V_45 ;
T_2 * V_50 ;
void * * V_23 ;
V_45 = (struct V_44 * ) F_3 ( V_41 ) ;
if ( V_45 -> V_9 . V_47 && V_45 -> V_9 . V_46 ) {
F_10 ( V_45 ) ;
return;
}
V_23 = ( void * ) F_3 ( & V_40 ) ;
V_50 = ( T_2 * ) F_3 ( & V_39 ) ;
if ( ! * V_23 || ! * V_50 )
return;
F_6 ( * V_23 , * V_50 , false ) ;
}
static void T_1 F_14 ( void * V_51 )
{
unsigned int V_52 = F_15 () ;
struct V_53 * V_54 = V_53 + V_52 ;
V_54 -> V_55 . V_56 = F_16 ( 0x00000001 ) ;
}
static void T_1 F_17 ( void )
{
unsigned int V_57 = V_58 . V_59 ;
struct V_53 * V_54 = V_53 + V_57 ;
if ( ! V_54 -> V_55 . V_56 )
F_18 ( V_57 , F_14 , NULL , 1 ) ;
}
void F_13 ( void )
{
unsigned int V_52 = F_15 () ;
struct V_53 * V_54 = V_53 + V_52 ;
struct V_25 * V_26 ;
struct V_44 * V_45 ;
T_4 V_32 , V_33 ;
T_5 V_30 ;
if ( ! V_52 )
return;
if ( ! V_40 )
return;
F_19 ( V_43 , V_32 , V_33 ) ;
V_54 -> V_55 . V_32 = V_32 ;
V_54 -> V_55 . V_56 = V_33 ;
V_33 = F_16 ( 0x00000001 ) ;
V_26 = (struct V_25 * ) ( V_40 + V_18 ) ;
V_30 = F_8 ( V_26 , V_33 ) ;
if ( ! V_30 )
return;
if ( V_30 == V_42 ) {
V_45 = (struct V_44 * ) V_41 ;
if ( V_45 && V_32 < V_45 -> V_9 . V_47 ) {
if ( ! F_10 ( V_45 ) )
V_38 = V_45 -> V_9 . V_47 ;
}
} else {
if ( ! V_49 . V_13 )
return;
F_6 ( V_49 . V_13 , V_49 . V_5 , false ) ;
}
}
int T_1 F_20 ( void )
{
unsigned long V_28 ;
int V_60 = 0 ;
enum V_61 V_62 ;
T_3 * V_63 ;
T_4 V_33 ;
if ( ! V_40 )
return - V_64 ;
#ifdef F_2
F_17 () ;
V_28 = ( unsigned long ) V_40 ;
V_63 = F_21 ( V_40 ) ;
#else
V_28 = F_22 ( V_40 ) ;
V_63 = V_40 ;
#endif
if ( V_65 )
V_40 = ( T_3 * ) ( F_21 ( V_65 ) +
( V_28 - V_6 . V_9 . V_10 ) ) ;
else
V_40 = V_63 ;
if ( V_38 )
F_23 ( L_1 ,
V_38 ) ;
V_33 = F_16 ( 0x00000001 ) ;
V_33 = ( ( V_33 >> 8 ) & 0xf ) + ( ( V_33 >> 20 ) & 0xff ) ;
V_62 = F_24 ( V_33 , V_40 , V_39 ) ;
if ( V_62 != V_66 )
V_60 = - V_64 ;
V_40 = NULL ;
V_39 = 0 ;
return V_60 ;
}
