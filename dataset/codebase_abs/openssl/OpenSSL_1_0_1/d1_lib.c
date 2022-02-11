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
static void F_8 ( T_1 * V_1 )
{
T_3 * V_14 = NULL ;
T_4 * V_15 = NULL ;
T_5 * V_16 ;
while( ( V_14 = F_9 ( V_1 -> V_2 -> V_3 . V_4 ) ) != NULL )
{
V_16 = ( T_5 * ) V_14 -> V_17 ;
if ( V_16 -> V_18 . V_19 )
{
F_7 ( V_16 -> V_18 . V_19 ) ;
}
F_7 ( V_14 -> V_17 ) ;
F_10 ( V_14 ) ;
}
while( ( V_14 = F_9 ( V_1 -> V_2 -> V_5 . V_4 ) ) != NULL )
{
V_16 = ( T_5 * ) V_14 -> V_17 ;
if ( V_16 -> V_18 . V_19 )
{
F_7 ( V_16 -> V_18 . V_19 ) ;
}
F_7 ( V_14 -> V_17 ) ;
F_10 ( V_14 ) ;
}
while( ( V_14 = F_9 ( V_1 -> V_2 -> V_6 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_17 ;
F_7 ( V_15 -> V_20 ) ;
F_7 ( V_15 ) ;
F_10 ( V_14 ) ;
}
while ( ( V_14 = F_9 ( V_1 -> V_2 -> V_7 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_17 ;
F_7 ( V_15 -> V_20 ) ;
F_7 ( V_15 ) ;
F_10 ( V_14 ) ;
}
while ( ( V_14 = F_9 ( V_1 -> V_2 -> V_8 . V_4 ) ) != NULL )
{
V_15 = ( T_4 * ) V_14 -> V_17 ;
F_7 ( V_15 -> V_20 ) ;
F_7 ( V_15 ) ;
F_10 ( V_14 ) ;
}
}
void F_11 ( T_1 * V_1 )
{
F_12 ( V_1 ) ;
F_8 ( V_1 ) ;
F_6 ( V_1 -> V_2 -> V_3 . V_4 ) ;
F_6 ( V_1 -> V_2 -> V_5 . V_4 ) ;
F_6 ( V_1 -> V_2 -> V_6 ) ;
F_6 ( V_1 -> V_2 -> V_7 ) ;
F_6 ( V_1 -> V_2 -> V_8 . V_4 ) ;
F_7 ( V_1 -> V_2 ) ;
}
void F_13 ( T_1 * V_1 )
{
T_6 V_3 ;
T_6 V_5 ;
T_6 V_6 ;
T_6 V_7 ;
T_6 V_8 ;
unsigned int V_21 ;
if ( V_1 -> V_2 )
{
V_3 = V_1 -> V_2 -> V_3 . V_4 ;
V_5 = V_1 -> V_2 -> V_5 . V_4 ;
V_6 = V_1 -> V_2 -> V_6 ;
V_7 = V_1 -> V_2 -> V_7 ;
V_8 = V_1 -> V_2 -> V_8 . V_4 ;
V_21 = V_1 -> V_2 -> V_21 ;
F_8 ( V_1 ) ;
memset ( V_1 -> V_2 , 0 , sizeof( * ( V_1 -> V_2 ) ) ) ;
if ( V_1 -> V_9 )
{
V_1 -> V_2 -> V_10 = sizeof( V_1 -> V_2 -> V_11 ) ;
}
if ( F_14 ( V_1 ) & V_22 )
{
V_1 -> V_2 -> V_21 = V_21 ;
}
V_1 -> V_2 -> V_3 . V_4 = V_3 ;
V_1 -> V_2 -> V_5 . V_4 = V_5 ;
V_1 -> V_2 -> V_6 = V_6 ;
V_1 -> V_2 -> V_7 = V_7 ;
V_1 -> V_2 -> V_8 . V_4 = V_8 ;
}
F_15 ( V_1 ) ;
if ( V_1 -> V_23 & V_24 )
V_1 -> V_25 = V_26 ;
else
V_1 -> V_25 = V_27 ;
}
long F_16 ( T_1 * V_1 , int V_28 , long V_29 , void * V_30 )
{
int V_31 = 0 ;
switch ( V_28 )
{
case V_32 :
if ( F_17 ( V_1 , (struct V_33 * ) V_30 ) != NULL )
{
V_31 = 1 ;
}
break;
case V_34 :
V_31 = F_18 ( V_1 ) ;
break;
case V_35 :
V_31 = F_19 ( V_1 , V_30 ) ;
break;
default:
V_31 = F_20 ( V_1 , V_28 , V_29 , V_30 ) ;
break;
}
return ( V_31 ) ;
}
const T_7 * F_21 ( unsigned int V_36 )
{
const T_7 * V_37 = F_22 ( V_36 ) ;
if ( V_37 != NULL )
{
if ( V_37 -> V_38 == V_39 )
return NULL ;
}
return V_37 ;
}
void F_23 ( T_1 * V_1 )
{
#ifndef F_24
if ( F_25 ( F_26 ( V_1 ) ) )
{
memset ( & ( V_1 -> V_2 -> V_40 ) , 0 , sizeof( struct V_33 ) ) ;
return;
}
#endif
if ( V_1 -> V_2 -> V_40 . V_41 == 0 && V_1 -> V_2 -> V_40 . V_42 == 0 )
{
V_1 -> V_2 -> V_43 = 1 ;
}
F_27 ( & ( V_1 -> V_2 -> V_40 ) ) ;
V_1 -> V_2 -> V_40 . V_41 += V_1 -> V_2 -> V_43 ;
F_28 ( F_29 ( V_1 ) , V_44 , 0 , & ( V_1 -> V_2 -> V_40 ) ) ;
}
struct V_33 * F_17 ( T_1 * V_1 , struct V_33 * V_45 )
{
struct V_33 V_46 ;
if ( V_1 -> V_2 -> V_40 . V_41 == 0 && V_1 -> V_2 -> V_40 . V_42 == 0 )
{
return NULL ;
}
F_27 ( & V_46 ) ;
if ( V_1 -> V_2 -> V_40 . V_41 < V_46 . V_41 ||
( V_1 -> V_2 -> V_40 . V_41 == V_46 . V_41 &&
V_1 -> V_2 -> V_40 . V_42 <= V_46 . V_42 ) )
{
memset ( V_45 , 0 , sizeof( struct V_33 ) ) ;
return V_45 ;
}
memcpy ( V_45 , & ( V_1 -> V_2 -> V_40 ) , sizeof( struct V_33 ) ) ;
V_45 -> V_41 -= V_46 . V_41 ;
V_45 -> V_42 -= V_46 . V_42 ;
if ( V_45 -> V_42 < 0 )
{
V_45 -> V_41 -- ;
V_45 -> V_42 += 1000000 ;
}
if ( V_45 -> V_41 == 0 && V_45 -> V_42 < 15000 )
{
memset ( V_45 , 0 , sizeof( struct V_33 ) ) ;
}
return V_45 ;
}
int F_30 ( T_1 * V_1 )
{
struct V_33 V_45 ;
if ( F_17 ( V_1 , & V_45 ) == NULL )
{
return 0 ;
}
if ( V_45 . V_41 > 0 || V_45 . V_42 > 0 )
{
return 0 ;
}
return 1 ;
}
void F_31 ( T_1 * V_1 )
{
V_1 -> V_2 -> V_43 *= 2 ;
if ( V_1 -> V_2 -> V_43 > 60 )
V_1 -> V_2 -> V_43 = 60 ;
F_23 ( V_1 ) ;
}
void F_32 ( T_1 * V_1 )
{
memset ( & ( V_1 -> V_2 -> V_47 ) , 0 , sizeof( struct V_48 ) ) ;
memset ( & ( V_1 -> V_2 -> V_40 ) , 0 , sizeof( struct V_33 ) ) ;
V_1 -> V_2 -> V_43 = 1 ;
F_28 ( F_29 ( V_1 ) , V_44 , 0 , & ( V_1 -> V_2 -> V_40 ) ) ;
F_33 ( V_1 ) ;
}
int F_34 ( T_1 * V_1 )
{
V_1 -> V_2 -> V_47 . V_49 ++ ;
if ( V_1 -> V_2 -> V_47 . V_49 > 2 )
{
V_1 -> V_2 -> V_21 = F_28 ( F_26 ( V_1 ) , V_50 , 0 , NULL ) ;
}
if ( V_1 -> V_2 -> V_47 . V_49 > V_51 )
{
F_35 ( V_52 , V_53 ) ;
return - 1 ;
}
return 0 ;
}
int F_18 ( T_1 * V_1 )
{
if ( ! F_30 ( V_1 ) )
{
return 0 ;
}
F_31 ( V_1 ) ;
if ( F_34 ( V_1 ) < 0 )
return - 1 ;
V_1 -> V_2 -> V_47 . V_54 ++ ;
if ( V_1 -> V_2 -> V_47 . V_54 > V_55 )
{
V_1 -> V_2 -> V_47 . V_54 = 1 ;
}
#ifndef F_36
if ( V_1 -> V_56 )
{
V_1 -> V_56 = 0 ;
return F_37 ( V_1 ) ;
}
#endif
F_23 ( V_1 ) ;
return F_38 ( V_1 ) ;
}
static void F_27 ( struct V_33 * V_57 )
{
#ifdef F_39
struct V_58 V_59 ;
F_40 ( & V_59 ) ;
V_57 -> V_41 = ( long ) V_59 . time ;
V_57 -> V_42 = ( long ) V_59 . V_60 * 1000 ;
#elif F_41 ( V_61 )
struct V_62 V_59 ;
F_42 ( & V_59 ) ;
V_57 -> V_41 = ( long ) V_59 . time ;
V_57 -> V_42 = ( long ) V_59 . V_60 * 1000 ;
#else
F_43 ( V_57 , NULL ) ;
#endif
}
int F_19 ( T_1 * V_1 , struct V_63 * V_64 )
{
int V_31 ;
F_44 ( V_1 , V_65 ) ;
V_1 -> V_2 -> V_66 = 1 ;
V_31 = F_45 ( V_1 ) ;
if ( V_31 <= 0 ) return V_31 ;
( void ) F_46 ( F_29 ( V_1 ) , V_64 ) ;
return 1 ;
}
