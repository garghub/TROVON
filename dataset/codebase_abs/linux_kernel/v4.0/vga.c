T_1
F_1 ( void * V_1 , int V_2 , T_2 V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_6 >= V_7 )
return F_3 ( V_1 , 0x601000 + V_3 ) ;
if ( V_3 == 0x03c0 || V_3 == 0x03c1 ||
V_3 == 0x03c2 || V_3 == 0x03da ||
V_3 == 0x03d4 || V_3 == 0x03d5 )
return F_3 ( V_1 , 0x601000 + ( V_2 * 0x2000 ) + V_3 ) ;
if ( V_3 == 0x03c2 || V_3 == 0x03cc ||
V_3 == 0x03c4 || V_3 == 0x03c5 ||
V_3 == 0x03ce || V_3 == 0x03cf ) {
if ( V_5 -> V_6 < V_8 )
V_2 = 0 ;
return F_3 ( V_1 , 0x0c0000 + ( V_2 * 0x2000 ) + V_3 ) ;
}
F_4 ( V_1 , L_1 , V_3 ) ;
return 0x00 ;
}
void
F_5 ( void * V_1 , int V_2 , T_2 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
if ( V_5 -> V_6 >= V_7 )
F_6 ( V_1 , 0x601000 + V_3 , V_9 ) ;
else
if ( V_3 == 0x03c0 || V_3 == 0x03c1 ||
V_3 == 0x03c2 || V_3 == 0x03da ||
V_3 == 0x03d4 || V_3 == 0x03d5 )
F_6 ( V_1 , 0x601000 + ( V_2 * 0x2000 ) + V_3 , V_9 ) ;
else
if ( V_3 == 0x03c2 || V_3 == 0x03cc ||
V_3 == 0x03c4 || V_3 == 0x03c5 ||
V_3 == 0x03ce || V_3 == 0x03cf ) {
if ( V_5 -> V_6 < V_8 )
V_2 = 0 ;
F_6 ( V_1 , 0x0c0000 + ( V_2 * 0x2000 ) + V_3 , V_9 ) ;
} else
F_4 ( V_1 , L_1 , V_3 ) ;
}
T_1
F_7 ( void * V_1 , int V_2 , T_1 V_10 )
{
F_5 ( V_1 , V_2 , 0x03c4 , V_10 ) ;
return F_1 ( V_1 , V_2 , 0x03c5 ) ;
}
void
F_8 ( void * V_1 , int V_2 , T_1 V_10 , T_1 V_11 )
{
F_5 ( V_1 , V_2 , 0x03c4 , V_10 ) ;
F_5 ( V_1 , V_2 , 0x03c5 , V_11 ) ;
}
T_1
F_9 ( void * V_1 , int V_2 , T_1 V_10 )
{
F_5 ( V_1 , V_2 , 0x03ce , V_10 ) ;
return F_1 ( V_1 , V_2 , 0x03cf ) ;
}
void
F_10 ( void * V_1 , int V_2 , T_1 V_10 , T_1 V_11 )
{
F_5 ( V_1 , V_2 , 0x03ce , V_10 ) ;
F_5 ( V_1 , V_2 , 0x03cf , V_11 ) ;
}
T_1
F_11 ( void * V_1 , int V_2 , T_1 V_10 )
{
F_5 ( V_1 , V_2 , 0x03d4 , V_10 ) ;
return F_1 ( V_1 , V_2 , 0x03d5 ) ;
}
void
F_12 ( void * V_1 , int V_2 , T_1 V_10 , T_1 V_11 )
{
F_5 ( V_1 , V_2 , 0x03d4 , V_10 ) ;
F_5 ( V_1 , V_2 , 0x03d5 , V_11 ) ;
}
T_1
F_13 ( void * V_1 , int V_2 , T_2 V_3 , T_1 V_10 )
{
if ( V_3 == 0x03c4 ) return F_7 ( V_1 , V_2 , V_10 ) ;
if ( V_3 == 0x03ce ) return F_9 ( V_1 , V_2 , V_10 ) ;
if ( V_3 == 0x03d4 ) return F_11 ( V_1 , V_2 , V_10 ) ;
F_4 ( V_1 , L_2 , V_3 ) ;
return 0x00 ;
}
void
F_14 ( void * V_1 , int V_2 , T_2 V_3 , T_1 V_10 , T_1 V_11 )
{
if ( V_3 == 0x03c4 ) F_8 ( V_1 , V_2 , V_10 , V_11 ) ;
else if ( V_3 == 0x03ce ) F_10 ( V_1 , V_2 , V_10 , V_11 ) ;
else if ( V_3 == 0x03d4 ) F_12 ( V_1 , V_2 , V_10 , V_11 ) ;
else F_4 ( V_1 , L_2 , V_3 ) ;
}
bool
F_15 ( void * V_1 , bool V_12 )
{
struct V_4 * V_13 = F_2 ( V_1 ) ;
bool V_14 = ! F_11 ( V_1 , 0 , 0x1f ) ;
T_1 V_9 = V_12 ? 0x99 : 0x57 ;
if ( V_13 -> V_6 < V_7 )
F_12 ( V_1 , 0 , 0x1f , V_9 ) ;
else
F_12 ( V_1 , 0 , 0x3f , V_9 ) ;
if ( V_13 -> V_15 == 0x11 ) {
if ( ! ( F_16 ( V_1 , 0x001084 ) & 0x10000000 ) )
F_12 ( V_1 , 1 , 0x1f , V_9 ) ;
}
return V_14 ;
}
T_1
F_17 ( void * V_1 )
{
if ( F_2 ( V_1 ) -> V_6 < V_7 ) {
if ( F_2 ( V_1 ) -> V_15 == 0x11 ) {
T_3 V_16 = F_16 ( V_1 , 0x001084 ) & 0x10000000 ;
if ( V_16 == 0 ) {
T_1 V_17 = F_11 ( V_1 , 0 , 0x28 ) & 0x80 ;
T_1 V_18 = F_11 ( V_1 , 0 , 0x33 ) & 0x01 ;
T_1 V_19 = F_11 ( V_1 , 1 , 0x28 ) & 0x80 ;
T_1 V_20 = F_11 ( V_1 , 1 , 0x33 ) & 0x01 ;
if ( V_17 && ! V_18 ) return 0x00 ;
if ( V_19 && ! V_20 ) return 0x03 ;
if ( V_17 ) return 0x00 ;
if ( V_19 ) return 0x03 ;
return 0x00 ;
}
return 0x04 ;
}
return F_11 ( V_1 , 0 , 0x44 ) ;
}
F_4 ( V_1 , L_3 ) ;
return 0x00 ;
}
void
F_18 ( void * V_1 , T_1 V_21 )
{
if ( F_2 ( V_1 ) -> V_6 < V_7 ) {
T_1 V_22 = ( V_21 == 1 ) ? 3 : V_21 ;
if ( F_2 ( V_1 ) -> V_15 == 0x11 ) {
F_11 ( V_1 , 0 , 0x1f ) ;
F_11 ( V_1 , 1 , 0x1f ) ;
}
F_12 ( V_1 , 0 , 0x44 , V_22 ) ;
if ( F_2 ( V_1 ) -> V_15 == 0x11 ) {
F_12 ( V_1 , 0 , 0x2e , V_22 ) ;
F_12 ( V_1 , 0 , 0x2e , V_22 ) ;
}
} else
F_4 ( V_1 , L_4 ) ;
}
