static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_2 -> V_3 = 0 ;
return true ;
} else
return false ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 == V_2 -> V_3 && ! F_1 ( V_2 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_5 , V_6 = 4 ;
T_1 V_7 ;
void * V_8 = & V_7 ;
do {
V_5 = F_5 ( V_2 -> V_4 - V_2 -> V_3 , V_6 ) ;
memcpy ( V_8 , V_2 -> V_8 + V_2 -> V_3 , V_5 ) ;
V_2 -> V_3 += V_5 ;
V_6 -= V_5 ;
if ( ! V_6 )
return V_7 ;
V_8 += V_5 ;
} while ( F_1 ( V_2 ) );
memset ( V_8 , 0 , V_6 ) ;
return V_7 ;
}
static inline bool F_6 ( const void * V_9 )
{
#ifdef F_7
return false ;
#else
return ( ( V_9 - NULL ) & 3 ) != 0 ;
#endif
}
static bool F_8 ( struct V_1 * V_2 , T_1 * * V_9 )
{
T_2 V_5 ;
if ( F_3 ( V_2 ) )
return true ;
V_5 = V_2 -> V_4 - V_2 -> V_3 ;
if ( F_9 ( V_5 >= 4 && ! F_6 (
V_2 -> V_8 + V_2 -> V_3 ) ) ) {
* V_9 = V_2 -> V_8 + V_2 -> V_3 ;
V_2 -> V_3 += 4 ;
return true ;
}
return false ;
}
T_1 F_10 ( struct V_1 * V_2 )
{
T_1 * V_9 = NULL ;
if ( F_9 ( F_8 ( V_2 , & V_9 ) ) )
return V_9 ? * V_9 : 0 ;
return F_4 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_7 )
{
T_2 V_5 , V_6 = 4 ;
void * V_8 = & V_7 ;
do {
V_5 = F_5 ( V_2 -> V_4 - V_2 -> V_3 , V_6 ) ;
memcpy ( V_2 -> V_8 , V_8 , V_5 ) ;
V_2 -> V_3 += V_5 ;
V_6 -= V_5 ;
if ( ! V_6 )
return;
V_8 += V_5 ;
} while ( F_1 ( V_2 ) );
}
void F_12 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 * V_9 = NULL ;
if ( F_9 ( F_8 ( V_2 , & V_9 ) ) ) {
if ( V_9 )
* V_9 = V_7 ;
else
return;
} else
F_11 ( V_2 , V_7 ) ;
}
