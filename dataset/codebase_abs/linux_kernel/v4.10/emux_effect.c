static void
F_1 ( unsigned char * V_1 , struct V_2 * V_3 , int type )
{
short V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
V_4 = V_6 -> V_8 [ type ] ;
if ( V_6 -> V_9 [ type ] == V_10 ) {
if ( V_11 [ type ] . type & V_12 )
V_4 += * ( char * ) V_1 ;
else
V_4 += * V_1 ;
}
if ( V_4 < V_11 [ type ] . V_13 )
V_4 = V_11 [ type ] . V_13 ;
else if ( V_4 > V_11 [ type ] . V_14 )
V_4 = V_11 [ type ] . V_14 ;
* V_1 = ( unsigned char ) V_4 ;
}
static void
F_2 ( unsigned short * V_1 , struct V_2 * V_3 , int type )
{
int V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
V_4 = * ( unsigned short * ) & V_6 -> V_8 [ type ] ;
if ( V_6 -> V_9 [ type ] == V_10 )
V_4 += * V_1 ;
if ( V_4 < V_11 [ type ] . V_13 )
V_4 = V_11 [ type ] . V_13 ;
else if ( V_4 > V_11 [ type ] . V_14 )
V_4 = V_11 [ type ] . V_14 ;
* V_1 = ( unsigned short ) V_4 ;
}
static int
F_3 ( struct V_2 * V_3 , int V_15 , int V_16 , int V_17 )
{
int V_18 = 0 ;
struct V_5 * V_6 = V_3 -> V_7 ;
if ( V_6 -> V_9 [ V_16 ] )
V_18 = ( short ) V_6 -> V_8 [ V_16 ] ;
V_18 = V_18 << 15 ;
if ( V_6 -> V_9 [ V_15 ] )
V_18 += ( short ) V_6 -> V_8 [ V_15 ] ;
if ( ! ( V_17 & V_19 ) )
V_18 /= 2 ;
return V_18 ;
}
void
F_4 ( struct V_20 * V_21 ,
struct V_2 * V_3 , int type , int V_8 )
{
int V_17 ;
if ( type & 0x40 )
V_17 = V_22 ;
else if ( type & 0x80 )
V_17 = V_10 ;
else
V_17 = V_23 ;
type &= 0x3f ;
F_5 ( V_21 , V_3 , type , V_8 , V_17 ) ;
}
void
F_5 ( struct V_20 * V_21 , struct V_2 * V_3 ,
int type , int V_8 , int V_17 )
{
int V_24 ;
int V_25 ;
unsigned char * V_26 , * V_27 ;
struct V_28 * V_29 ;
struct V_5 * V_6 ;
unsigned long V_30 ;
V_29 = V_21 -> V_29 ;
V_6 = V_3 -> V_7 ;
if ( V_29 == NULL || V_6 == NULL )
return;
if ( type < 0 || type >= V_31 )
return;
V_6 -> V_8 [ type ] = V_8 ;
V_6 -> V_9 [ type ] = V_17 ;
if ( ! V_11 [ type ] . V_32 || ( V_25 = V_11 [ type ] . V_25 ) < 0 )
return;
#ifdef F_6
if ( V_11 [ type ] . type & V_33 )
V_25 ++ ;
#else
if ( V_11 [ type ] . type & V_34 )
V_25 ++ ;
#endif
F_7 ( & V_29 -> V_35 , V_30 ) ;
for ( V_24 = 0 ; V_24 < V_29 -> V_36 ; V_24 ++ ) {
struct V_37 * V_38 = & V_29 -> V_39 [ V_24 ] ;
if ( ! F_8 ( V_38 -> V_40 ) || V_38 -> V_3 != V_3 )
continue;
V_26 = ( unsigned char * ) & V_38 -> V_41 . V_42 + V_25 ;
V_27 = ( unsigned char * ) & V_38 -> V_43 -> V_44 . V_42 + V_25 ;
if ( V_11 [ V_24 ] . type & V_45 ) {
* V_26 = * V_27 ;
F_1 ( V_26 , V_3 , type ) ;
} else {
* ( unsigned short * ) V_26 = * ( unsigned short * ) V_27 ;
F_2 ( ( unsigned short * ) V_26 , V_3 , type ) ;
}
}
F_9 ( & V_29 -> V_35 , V_30 ) ;
F_10 ( V_21 , V_3 , V_11 [ type ] . V_32 ) ;
}
void
F_11 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = V_38 -> V_3 ;
struct V_5 * V_6 ;
unsigned char * V_26 ;
int V_24 ;
if ( ! ( V_6 = V_3 -> V_7 ) )
return;
for ( V_24 = 0 ; V_24 < V_46 ; V_24 ++ ) {
int V_25 ;
if ( ! V_6 -> V_9 [ V_24 ] || ( V_25 = V_11 [ V_24 ] . V_25 ) < 0 )
continue;
#ifdef F_6
if ( V_11 [ V_24 ] . type & V_33 )
V_25 ++ ;
#else
if ( V_11 [ V_24 ] . type & V_34 )
V_25 ++ ;
#endif
V_26 = ( unsigned char * ) & V_38 -> V_41 . V_42 + V_25 ;
if ( V_11 [ V_24 ] . type & V_45 )
F_1 ( V_26 , V_3 , V_24 ) ;
else
F_2 ( ( unsigned short * ) V_26 , V_3 , V_24 ) ;
}
V_38 -> V_41 . V_47 += F_3 ( V_3 , V_48 ,
V_49 ,
V_38 -> V_41 . V_50 ) ;
V_38 -> V_41 . V_51 += F_3 ( V_3 , V_52 ,
V_53 ,
V_38 -> V_41 . V_50 ) ;
V_38 -> V_41 . V_54 += F_3 ( V_3 , V_55 ,
V_56 ,
V_38 -> V_41 . V_50 ) ;
}
void
F_12 ( struct V_20 * V_57 )
{
int V_24 ;
V_57 -> V_4 = F_13 ( V_57 -> V_58 . V_59 ,
sizeof( struct V_5 ) , V_60 ) ;
if ( V_57 -> V_4 ) {
for ( V_24 = 0 ; V_24 < V_57 -> V_58 . V_59 ; V_24 ++ )
V_57 -> V_58 . V_61 [ V_24 ] . V_7 = V_57 -> V_4 + V_24 ;
} else {
for ( V_24 = 0 ; V_24 < V_57 -> V_58 . V_59 ; V_24 ++ )
V_57 -> V_58 . V_61 [ V_24 ] . V_7 = NULL ;
}
}
void
F_14 ( struct V_20 * V_57 )
{
F_15 ( V_57 -> V_4 ) ;
V_57 -> V_4 = NULL ;
}
void
F_16 ( struct V_20 * V_57 )
{
if ( V_57 -> V_4 ) {
memset ( V_57 -> V_4 , 0 , sizeof( struct V_5 ) *
V_57 -> V_58 . V_59 ) ;
}
}
