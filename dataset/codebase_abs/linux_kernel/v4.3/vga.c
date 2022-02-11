T_1
F_1 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 >= V_6 )
return F_2 ( V_2 , 0x601000 + V_4 ) ;
if ( V_4 == 0x03c0 || V_4 == 0x03c1 ||
V_4 == 0x03c2 || V_4 == 0x03da ||
V_4 == 0x03d4 || V_4 == 0x03d5 )
return F_2 ( V_2 , 0x601000 + ( V_3 * 0x2000 ) + V_4 ) ;
if ( V_4 == 0x03c2 || V_4 == 0x03cc ||
V_4 == 0x03c4 || V_4 == 0x03c5 ||
V_4 == 0x03ce || V_4 == 0x03cf ) {
if ( V_2 -> V_5 < V_7 )
V_3 = 0 ;
return F_2 ( V_2 , 0x0c0000 + ( V_3 * 0x2000 ) + V_4 ) ;
}
return 0x00 ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , T_1 V_8 )
{
if ( V_2 -> V_5 >= V_6 )
F_4 ( V_2 , 0x601000 + V_4 , V_8 ) ;
else
if ( V_4 == 0x03c0 || V_4 == 0x03c1 ||
V_4 == 0x03c2 || V_4 == 0x03da ||
V_4 == 0x03d4 || V_4 == 0x03d5 )
F_4 ( V_2 , 0x601000 + ( V_3 * 0x2000 ) + V_4 , V_8 ) ;
else
if ( V_4 == 0x03c2 || V_4 == 0x03cc ||
V_4 == 0x03c4 || V_4 == 0x03c5 ||
V_4 == 0x03ce || V_4 == 0x03cf ) {
if ( V_2 -> V_5 < V_7 )
V_3 = 0 ;
F_4 ( V_2 , 0x0c0000 + ( V_3 * 0x2000 ) + V_4 , V_8 ) ;
}
}
T_1
F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
F_3 ( V_2 , V_3 , 0x03c4 , V_9 ) ;
return F_1 ( V_2 , V_3 , 0x03c5 ) ;
}
void
F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_9 , T_1 V_10 )
{
F_3 ( V_2 , V_3 , 0x03c4 , V_9 ) ;
F_3 ( V_2 , V_3 , 0x03c5 , V_10 ) ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
F_3 ( V_2 , V_3 , 0x03ce , V_9 ) ;
return F_1 ( V_2 , V_3 , 0x03cf ) ;
}
void
F_8 ( struct V_1 * V_2 , int V_3 , T_1 V_9 , T_1 V_10 )
{
F_3 ( V_2 , V_3 , 0x03ce , V_9 ) ;
F_3 ( V_2 , V_3 , 0x03cf , V_10 ) ;
}
T_1
F_9 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
F_3 ( V_2 , V_3 , 0x03d4 , V_9 ) ;
return F_1 ( V_2 , V_3 , 0x03d5 ) ;
}
void
F_10 ( struct V_1 * V_2 , int V_3 , T_1 V_9 , T_1 V_10 )
{
F_3 ( V_2 , V_3 , 0x03d4 , V_9 ) ;
F_3 ( V_2 , V_3 , 0x03d5 , V_10 ) ;
}
T_1
F_11 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , T_1 V_9 )
{
if ( V_4 == 0x03c4 ) return F_5 ( V_2 , V_3 , V_9 ) ;
if ( V_4 == 0x03ce ) return F_7 ( V_2 , V_3 , V_9 ) ;
if ( V_4 == 0x03d4 ) return F_9 ( V_2 , V_3 , V_9 ) ;
return 0x00 ;
}
void
F_12 ( struct V_1 * V_2 , int V_3 , T_2 V_4 , T_1 V_9 , T_1 V_10 )
{
if ( V_4 == 0x03c4 ) F_6 ( V_2 , V_3 , V_9 , V_10 ) ;
else if ( V_4 == 0x03ce ) F_8 ( V_2 , V_3 , V_9 , V_10 ) ;
else if ( V_4 == 0x03d4 ) F_10 ( V_2 , V_3 , V_9 , V_10 ) ;
}
bool
F_13 ( struct V_1 * V_2 , bool V_11 )
{
bool V_12 = ! F_9 ( V_2 , 0 , 0x1f ) ;
T_1 V_8 = V_11 ? 0x99 : 0x57 ;
if ( V_2 -> V_5 < V_6 )
F_10 ( V_2 , 0 , 0x1f , V_8 ) ;
else
F_10 ( V_2 , 0 , 0x3f , V_8 ) ;
if ( V_2 -> V_13 == 0x11 ) {
if ( ! ( F_14 ( V_2 , 0x001084 ) & 0x10000000 ) )
F_10 ( V_2 , 1 , 0x1f , V_8 ) ;
}
return V_12 ;
}
T_1
F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 < V_6 ) {
if ( V_2 -> V_13 == 0x11 ) {
T_3 V_14 = F_14 ( V_2 , 0x001084 ) & 0x10000000 ;
if ( V_14 == 0 ) {
T_1 V_15 = F_9 ( V_2 , 0 , 0x28 ) & 0x80 ;
T_1 V_16 = F_9 ( V_2 , 0 , 0x33 ) & 0x01 ;
T_1 V_17 = F_9 ( V_2 , 1 , 0x28 ) & 0x80 ;
T_1 V_18 = F_9 ( V_2 , 1 , 0x33 ) & 0x01 ;
if ( V_15 && ! V_16 ) return 0x00 ;
if ( V_17 && ! V_18 ) return 0x03 ;
if ( V_15 ) return 0x00 ;
if ( V_17 ) return 0x03 ;
return 0x00 ;
}
return 0x04 ;
}
return F_9 ( V_2 , 0 , 0x44 ) ;
}
return 0x00 ;
}
void
F_16 ( struct V_1 * V_2 , T_1 V_19 )
{
if ( V_2 -> V_5 < V_6 ) {
T_1 V_20 = ( V_19 == 1 ) ? 3 : V_19 ;
if ( V_2 -> V_13 == 0x11 ) {
F_9 ( V_2 , 0 , 0x1f ) ;
F_9 ( V_2 , 1 , 0x1f ) ;
}
F_10 ( V_2 , 0 , 0x44 , V_20 ) ;
if ( V_2 -> V_13 == 0x11 ) {
F_10 ( V_2 , 0 , 0x2e , V_20 ) ;
F_10 ( V_2 , 0 , 0x2e , V_20 ) ;
}
}
}
