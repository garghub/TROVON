long F_1 ( void )
{
return ( 60 * 60 * 2 ) ;
}
int F_2 ( T_1 * V_1 )
{
T_2 * V_2 ;
if ( ! F_3 ( V_1 ) ) return ( 0 ) ;
if ( ( V_2 = F_4 ( sizeof *V_2 ) ) == NULL ) return ( 0 ) ;
memset ( V_2 , 0 , sizeof *V_2 ) ;
V_2 -> V_3 . V_4 = F_5 () ;
V_2 -> V_5 . V_4 = F_5 () ;
V_2 -> V_6 = F_5 () ;
V_2 -> V_7 = F_5 () ;
V_2 -> V_8 . V_4 = F_5 () ;
if ( V_1 -> V_9 )
{
V_2 -> V_10 = sizeof( V_1 -> V_2 -> V_11 ) ;
}
if( ! V_2 -> V_3 . V_4 || ! V_2 -> V_5 . V_4
|| ! V_2 -> V_6 || ! V_2 -> V_7 || ! V_2 -> V_8 . V_4 )
{
if ( V_2 -> V_3 . V_4 ) F_6 ( V_2 -> V_3 . V_4 ) ;
if ( V_2 -> V_5 . V_4 ) F_6 ( V_2 -> V_5 . V_4 ) ;
if ( V_2 -> V_6 ) F_6 ( V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) F_6 ( V_2 -> V_7 ) ;
if ( V_2 -> V_8 . V_4 ) F_6 ( V_2 -> V_8 . V_4 ) ;
F_7 ( V_2 ) ;
return ( 0 ) ;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_12 -> V_13 ( V_1 ) ;
return ( 1 ) ;
}
void F_8 ( T_1 * V_1 )
{
T_3 * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_9 ( V_1 ) ;
while( ( V_14 = F_10 ( V_1 -> V_2 -> V_3 . V_4 ) ) != NULL )
{
F_7 ( V_14 -> V_16 ) ;
F_11 ( V_14 ) ;
}
F_6 ( V_1 -> V_2 -> V_3 . V_4 ) ;
while( ( V_14 = F_10 ( V_1 -> V_2 -> V_5 . V_4 ) ) != NULL )
{
F_7 ( V_14 -> V_16 ) ;
F_11 ( V_14 ) ;
}
F_6 ( V_1 -> V_2 -> V_5 . V_4 ) ;
while( ( V_14 = F_10 ( V_1 -> V_2 -> V_6 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_16 ;
F_7 ( V_15 -> V_17 ) ;
F_7 ( V_15 ) ;
F_11 ( V_14 ) ;
}
F_6 ( V_1 -> V_2 -> V_6 ) ;
while ( ( V_14 = F_10 ( V_1 -> V_2 -> V_7 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_16 ;
F_7 ( V_15 -> V_17 ) ;
F_7 ( V_15 ) ;
F_11 ( V_14 ) ;
}
F_6 ( V_1 -> V_2 -> V_7 ) ;
while ( ( V_14 = F_10 ( V_1 -> V_2 -> V_8 . V_4 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_16 ;
F_7 ( V_15 -> V_17 ) ;
F_7 ( V_15 ) ;
F_11 ( V_14 ) ;
}
F_6 ( V_1 -> V_2 -> V_8 . V_4 ) ;
F_7 ( V_1 -> V_2 ) ;
}
void F_12 ( T_1 * V_1 )
{
F_13 ( V_1 ) ;
if ( V_1 -> V_18 & V_19 )
V_1 -> V_20 = V_21 ;
else
V_1 -> V_20 = V_22 ;
}
long F_14 ( T_1 * V_1 , int V_23 , long V_24 , void * V_25 )
{
int V_26 = 0 ;
switch ( V_23 )
{
case V_27 :
if ( F_15 ( V_1 , (struct V_28 * ) V_25 ) != NULL )
{
V_26 = 1 ;
}
break;
case V_29 :
V_26 = F_16 ( V_1 ) ;
break;
case V_30 :
V_26 = F_17 ( V_1 , V_25 ) ;
break;
default:
V_26 = F_18 ( V_1 , V_23 , V_24 , V_25 ) ;
break;
}
return ( V_26 ) ;
}
const T_5 * F_19 ( unsigned int V_31 )
{
const T_5 * V_32 = F_20 ( V_31 ) ;
if ( V_32 != NULL )
{
if ( V_32 -> V_33 == V_34 )
return NULL ;
}
return V_32 ;
}
void F_21 ( T_1 * V_1 )
{
if ( V_1 -> V_2 -> V_35 . V_36 == 0 && V_1 -> V_2 -> V_35 . V_37 == 0 )
{
V_1 -> V_2 -> V_38 = 1 ;
}
F_22 ( & ( V_1 -> V_2 -> V_35 ) ) ;
V_1 -> V_2 -> V_35 . V_36 += V_1 -> V_2 -> V_38 ;
F_23 ( F_24 ( V_1 ) , V_39 , 0 , & ( V_1 -> V_2 -> V_35 ) ) ;
}
struct V_28 * F_15 ( T_1 * V_1 , struct V_28 * V_40 )
{
struct V_28 V_41 ;
if ( V_1 -> V_2 -> V_35 . V_36 == 0 && V_1 -> V_2 -> V_35 . V_37 == 0 )
{
return NULL ;
}
F_22 ( & V_41 ) ;
if ( V_1 -> V_2 -> V_35 . V_36 < V_41 . V_36 ||
( V_1 -> V_2 -> V_35 . V_36 == V_41 . V_36 &&
V_1 -> V_2 -> V_35 . V_37 <= V_41 . V_37 ) )
{
memset ( V_40 , 0 , sizeof( struct V_28 ) ) ;
return V_40 ;
}
memcpy ( V_40 , & ( V_1 -> V_2 -> V_35 ) , sizeof( struct V_28 ) ) ;
V_40 -> V_36 -= V_41 . V_36 ;
V_40 -> V_37 -= V_41 . V_37 ;
if ( V_40 -> V_37 < 0 )
{
V_40 -> V_36 -- ;
V_40 -> V_37 += 1000000 ;
}
return V_40 ;
}
int F_25 ( T_1 * V_1 )
{
struct V_28 V_40 ;
if ( F_15 ( V_1 , & V_40 ) == NULL )
{
return 0 ;
}
if ( V_40 . V_36 > 0 || V_40 . V_37 > 0 )
{
return 0 ;
}
return 1 ;
}
void F_26 ( T_1 * V_1 )
{
V_1 -> V_2 -> V_38 *= 2 ;
if ( V_1 -> V_2 -> V_38 > 60 )
V_1 -> V_2 -> V_38 = 60 ;
F_21 ( V_1 ) ;
}
void F_27 ( T_1 * V_1 )
{
memset ( & ( V_1 -> V_2 -> V_35 ) , 0 , sizeof( struct V_28 ) ) ;
V_1 -> V_2 -> V_38 = 1 ;
F_23 ( F_24 ( V_1 ) , V_39 , 0 , & ( V_1 -> V_2 -> V_35 ) ) ;
}
int F_16 ( T_1 * V_1 )
{
T_2 * V_42 ;
if ( ! F_25 ( V_1 ) )
{
return 0 ;
}
F_26 ( V_1 ) ;
V_42 = V_1 -> V_2 ;
V_42 -> V_43 . V_44 ++ ;
if ( V_42 -> V_43 . V_44 > V_45 )
{
F_28 ( V_46 , V_47 ) ;
return 0 ;
}
V_42 -> V_43 . V_48 ++ ;
if ( V_42 -> V_43 . V_48 > V_49 )
{
V_42 -> V_43 . V_48 = 1 ;
}
F_21 ( V_1 ) ;
return F_29 ( V_1 ) ;
}
static void F_22 ( struct V_28 * V_50 )
{
#ifdef F_30
struct V_51 V_52 ;
F_31 ( & V_52 ) ;
V_50 -> V_36 = ( long ) V_52 . time ;
V_50 -> V_37 = ( long ) V_52 . V_53 * 1000 ;
#elif F_32 ( V_54 )
struct V_55 V_52 ;
F_33 ( & V_52 ) ;
V_50 -> V_36 = ( long ) V_52 . time ;
V_50 -> V_37 = ( long ) V_52 . V_53 * 1000 ;
#else
F_34 ( V_50 , NULL ) ;
#endif
}
int F_17 ( T_1 * V_1 , struct V_56 * V_57 )
{
int V_26 ;
F_35 ( V_1 , V_58 ) ;
V_1 -> V_2 -> V_59 = 1 ;
V_26 = F_36 ( V_1 ) ;
if ( V_26 <= 0 ) return V_26 ;
( void ) F_37 ( F_24 ( V_1 ) , V_57 ) ;
return 1 ;
}
