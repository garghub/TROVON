struct V_1 * F_1 ( T_1 V_2 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 && ( V_2 & V_5 -> V_7 ) == V_5 -> V_2 )
return V_5 ;
return NULL ;
}
struct V_1 * F_3 ( T_1 V_2 ,
T_1 V_7 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 && V_5 -> V_2 == V_2 && V_5 -> V_7 == V_7 )
return V_5 ;
return NULL ;
}
struct V_8 * F_4 ( const struct V_9 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_5 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 &&
F_5 ( & V_5 -> V_2 , & V_5 -> V_7 , V_2 ) == 0 )
return V_5 ;
return NULL ;
}
struct V_8 * F_6 ( const struct V_9 * V_2 ,
const struct V_9 * V_7 ,
struct V_3 * V_4 )
{
struct V_8 * V_5 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 &&
F_7 ( & V_5 -> V_2 , V_2 ) &&
F_7 ( & V_5 -> V_7 , V_7 ) )
return V_5 ;
return NULL ;
}
int F_8 ( struct V_1 * V_10 , struct V_3 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_10 -> V_2 , V_4 ) ;
if ( V_5 != NULL &&
V_5 -> V_2 == V_10 -> V_2 && V_5 -> V_7 == V_10 -> V_7 )
return - V_11 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 &&
F_9 ( V_10 -> V_7 ) > F_9 ( V_5 -> V_7 ) ) {
F_10 ( & V_10 -> V_12 ,
V_5 -> V_12 . V_13 ,
& V_5 -> V_12 ) ;
return 0 ;
}
F_11 ( & V_10 -> V_12 , V_4 ) ;
return 0 ;
}
int F_12 ( struct V_8 * V_10 , struct V_3 * V_4 )
{
struct V_8 * V_5 ;
V_5 = F_4 ( & V_10 -> V_2 , V_4 ) ;
if ( V_5 != NULL &&
F_7 ( & V_5 -> V_2 , & V_10 -> V_2 ) &&
F_7 ( & V_5 -> V_7 , & V_10 -> V_7 ) )
return - V_11 ;
F_2 (iter, head, list)
if ( V_5 -> V_6 &&
F_13 ( & V_10 -> V_7 , & V_5 -> V_7 ) > 0 ) {
F_10 ( & V_10 -> V_12 ,
V_5 -> V_12 . V_13 ,
& V_5 -> V_12 ) ;
return 0 ;
}
F_11 ( & V_10 -> V_12 , V_4 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_10 )
{
V_10 -> V_6 = 0 ;
F_15 ( & V_10 -> V_12 ) ;
}
struct V_1 * F_16 ( T_1 V_2 , T_1 V_7 ,
struct V_3 * V_4 )
{
struct V_1 * V_10 ;
V_10 = F_3 ( V_2 , V_7 , V_4 ) ;
if ( V_10 == NULL )
return NULL ;
F_14 ( V_10 ) ;
return V_10 ;
}
void F_17 ( struct V_8 * V_10 )
{
V_10 -> V_6 = 0 ;
F_15 ( & V_10 -> V_12 ) ;
}
struct V_8 * F_18 ( const struct V_9 * V_2 ,
const struct V_9 * V_7 ,
struct V_3 * V_4 )
{
struct V_8 * V_10 ;
V_10 = F_6 ( V_2 , V_7 , V_4 ) ;
if ( V_10 == NULL )
return NULL ;
F_17 ( V_10 ) ;
return V_10 ;
}
void F_19 ( struct V_14 * V_15 ,
int V_16 , const char * V_17 ,
T_1 V_2 , T_1 V_7 )
{
T_2 V_18 = F_9 ( V_7 ) ;
char * V_19 = ( V_16 ? L_1 : L_2 ) ;
if ( V_17 != NULL )
F_20 ( V_15 , L_3 , V_17 ) ;
F_20 ( V_15 , L_4 , V_19 , & V_2 ) ;
if ( V_18 != 0xffffffff ) {
T_2 V_20 = 0 ;
while ( V_18 > 0 ) {
V_18 <<= 1 ;
V_20 ++ ;
}
F_20 ( V_15 , L_5 , V_19 , V_20 ) ;
}
}
void F_21 ( struct V_14 * V_15 ,
int V_16 ,
const char * V_17 ,
const struct V_9 * V_2 ,
const struct V_9 * V_7 )
{
char * V_19 = ( V_16 ? L_1 : L_2 ) ;
if ( V_17 != NULL )
F_20 ( V_15 , L_3 , V_17 ) ;
F_20 ( V_15 , L_6 , V_19 , V_2 ) ;
if ( F_9 ( V_7 -> V_21 [ 3 ] ) != 0xffffffff ) {
T_2 V_20 = 0 ;
T_2 V_18 ;
int V_5 = - 1 ;
while ( F_9 ( V_7 -> V_21 [ ++ V_5 ] ) == 0xffffffff )
V_20 += 32 ;
V_18 = F_9 ( V_7 -> V_21 [ V_5 ] ) ;
while ( V_18 > 0 ) {
V_18 <<= 1 ;
V_20 ++ ;
}
F_20 ( V_15 , L_5 , V_19 , V_20 ) ;
}
}
