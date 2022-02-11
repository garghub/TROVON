struct V_1 *
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_1 V_4 , V_5 ;
int V_6 , exp ;
F_2 ( V_7 , L_1 ) ;
F_3 ( V_2 , V_3 ) ;
if ( F_4 ( V_2 ) )
return V_2 ;
if ( V_2 -> V_8 ) {
F_5 ( V_2 ) ;
return V_2 ;
}
if ( F_6 ( V_2 ) )
return V_2 ;
exp = V_2 -> exp ;
V_2 -> exp = 0x3FFF ;
if ( ! ( exp & 1 ) )
V_2 -> exp ++ ;
F_7 ( & V_5 , V_2 ) ;
F_8 ( V_2 , & V_9 ) ;
V_2 -> exp -- ;
for ( V_6 = 0 ; V_6 < 9 ; V_6 ++ ) {
F_7 ( & V_4 , & V_5 ) ;
F_9 ( & V_4 , V_2 ) ;
F_8 ( V_2 , & V_4 ) ;
V_2 -> exp -- ;
}
V_2 -> exp += ( exp - 0x3FFF ) / 2 ;
return V_2 ;
}
struct V_1 *
F_10 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_2 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_12 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_3 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_13 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_4 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_14 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_5 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_15 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_6 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_16 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_7 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_17 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_8 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_18 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_11 ( L_9 ) ;
F_3 ( V_2 , V_3 ) ;
return V_2 ;
}
struct V_1 *
F_19 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_7 , L_10 ) ;
F_3 ( V_2 , V_3 ) ;
if ( F_6 ( V_2 ) ) {
F_5 ( V_2 ) ;
return V_2 ;
}
if ( F_4 ( V_2 ) )
return V_2 ;
F_20 ( V_2 , ( int ) V_2 -> exp - 0x3FFF ) ;
F_21 ( V_2 ) ;
return V_2 ;
}
struct V_1 *
F_22 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( V_7 , L_11 ) ;
F_3 ( V_2 , V_3 ) ;
if ( F_4 ( V_2 ) )
return V_2 ;
if ( F_6 ( V_2 ) )
return V_2 ;
V_2 -> exp = 0x3FFF ;
return V_2 ;
}
